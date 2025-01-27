/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2025/01/27 23:10:43 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_split(char **split) {
    int i = 0;

    if (!split)
        return;
    while (split[i]) {
        free(split[i]);
        i++;
    }
    free(split);
}

void final_cleaner(t_files *file)
{
    int i;

    // Fecha os arquivos de entrada e saída, se estiverem abertos
    if (file->infile >= 0)
        close(file->infile);
    if (file->outfile >= 0)
        close(file->outfile);

    // Libera os comandos armazenados em `file->cmds`
    if (file->cmds)
    {
        i = 0;
        while (i < file->cmd_count)
        {
            if (file->cmds[i])
            {
                int j = 0;
                while (file->cmds[i][j]) // Libera cada argumento do comando
                {
                    free(file->cmds[i][j]);
                    j++;
                }
                free(file->cmds[i]); // Libera o array de argumentos
            }
            i++;
        }
        free(file->cmds); // Libera o array principal de comandos
    }
}


void path_cleaner(char **paths)
{
	int i = 0;

	while (paths && paths[i])
	{
		if (i == 0)
			free(paths[i] - 5); // Ajuste para a string "PATH="
		else
			free(paths[i]);
		i++;
	}
	if (paths)
		free(paths);
}

void pick_path2(t_files *file, char **path, int cmd_index, int path_index)
{
	char *tmp;

	// Cria o caminho base com o diretório do PATH
	tmp = ft_strjoin(path[path_index], "/");
	if (!tmp)
	{
		path_cleaner(path);      // Limpa os caminhos
		final_cleaner(file);     // Libera os recursos do arquivo
		exit(EXIT_FAILURE);      // Sai com erro
	}

	// Concatena o comando ao caminho base
	file->cmds[cmd_index][0] = ft_strjoin(tmp, file->cmds[cmd_index][0]);
	free(tmp);                  // Libera o caminho temporário

	if (!file->cmds[cmd_index][0]) // Verifica se a alocação foi bem-sucedida
	{
		path_cleaner(path);      // Limpa os caminhos
		final_cleaner(file);     // Libera os recursos do arquivo
		exit(EXIT_FAILURE);      // Sai com erro
	}
}

char **pick_path(char **envp)
{
	char **path = NULL;
	int index = 0;

	while (envp && envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{
			path = ft_split(envp[index], ':');
			if (!path)
				path_cleaner(path);
			else
				path[0] = path[0] + 5; // Ignorar "PATH="
			break;
		}
		index++;
	}
	return (path);
}

void search_path(t_files *file, char **paths)
{
	int i, n, check;

	for (n = 0; n < file->cmd_count; n++) // Itera pelos comandos
	{
		i = 0;
		check = 0;
		while (paths && paths[i])
		{
			char *tmp = ft_strjoin(paths[i], "/");
			char *full_path = ft_strjoin(tmp, file->cmds[n][0]);
			free(tmp);

			if (access(full_path, X_OK) == 0) // Verifica se o comando é executável
			{
				free(file->cmds[n][0]);
				file->cmds[n][0] = full_path; // Substitui pelo caminho completo
				check = 1;
				break;
			}
			free(full_path);
			i++;
		}
		if (!check) // Se não encontrou o comando, define como NULL
		{
			file->cmds[n][0] = NULL;
		}
	}
	path_cleaner(paths);
}

void execute_command(char **cmd_args, char **envp) {
    char **args = NULL;
    int fd = -1;

    // Verifica se há redirecionamento de entrada
    if (cmd_args && ft_strchr(cmd_args[0], '<')) {
        char **split = ft_split(cmd_args[0], '<'); // Separa comando e arquivo
        if (!split || !split[0] || !split[1]) {
            perror("Invalid redirection");
            exit(1);
        }
        args = ft_split(split[0], ' '); // Separa os argumentos do comando
        fd = open(ft_strtrim(split[1], " "), O_RDONLY); // Abre o arquivo redirecionado
        if (fd < 0) {
            perror("open");
            exit(1);
        }
        dup2(fd, STDIN_FILENO); // Redireciona entrada padrão
        close(fd);
        free_split(split);
    } else {
        args = cmd_args; // Se não houver redirecionamento, usa os comandos passados
    }

    if (!args || !args[0]) {
        perror("Invalid command");
        exit(1);
    }

    // Executa o comando
    execve(args[0], args, envp);
    perror("execve");
    exit(127);
}


void pipex(int argc, char **argv, char **envp)
{
	t_files file;
	int pipe_fd[2];
	int fd_in;
	pid_t pid;
	int i;

	// Inicializa estrutura
	file.envp = envp;
	file.cmd_count = argc - 3; // Exclui infile e outfile
	file.cmds = malloc(sizeof(char **) * file.cmd_count);
	for (i = 0; i < file.cmd_count; i++)
		file.cmds[i] = ft_split(argv[2 + i], ' ');

	// Busca caminhos para os comandos
	char **paths = pick_path(envp);
	search_path(&file, paths);

	// Abre arquivo de entrada
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
	{
		perror("open infile");
		exit(1);
	}

	// Processa cada comando
	for (i = 0; i < file.cmd_count - 1; i++)
	{
		if (pipe(pipe_fd) == -1)
		{
			perror("pipe");
			exit(1);
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(1);
		}

		if (pid == 0) // Processo filho
		{
			dup2(fd_in, STDIN_FILENO);  // Entrada padrão
			dup2(pipe_fd[1], STDOUT_FILENO); // Saída padrão
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			execute_command(file.cmds[i], envp);
		}
		else // Processo pai
		{
			waitpid(pid, NULL, 0);
			close(pipe_fd[1]);
			fd_in = pipe_fd[0];
		}
	}

	// Último comando
	int fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0)
	{
		perror("open outfile");
		exit(1);
	}

	pid = fork();
	if (pid == 0)
	{
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		execute_command(file.cmds[i], envp);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(fd_in);
		close(fd_out);
	}

	// Libera memória
	for (i = 0; i < file.cmd_count; i++)
		free(file.cmds[i]);
	free(file.cmds);
}

int main(int argc, char **argv, char **envp) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s infile cmd1 cmd2 ... cmdN outfile\n", argv[0]);
        return (1);
    }

    pipex(argc, argv, envp);
    return (0);
}


// int	main(int argc, char **argv, char **envp)
// {
// 	int		end[2];
// 	pid_t	child1;
// 	pid_t	child2;
// 	t_files	file;

// 	file.envp = envp;
// 	checker(argc, envp);
// 	file.infile = open(argv[1], O_RDONLY);
// 	check_file(file.infile);
// 	file.outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	check_file(file.outfile);
// 	check_pipe(end, file);
// 	child1 = fork();
// 	check_start_child1(child1, end, argv, file);
// 	child2 = fork();
// 	check_start_child2(child2, end, argv, file);
// 	close_files(end, file);
// 	wait(&child1);
// 	wait(&child2);
// 	return (0);
// }