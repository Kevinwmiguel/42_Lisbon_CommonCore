/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2025/02/02 19:21:19 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int here_doc(t_files *file)
{
    char    *line;
    int     fd[2];

    if (pipe(file->pipe_fd) == -1) // Use a estrutura file para gerenciar o pipe
    {
        perror("Erro ao criar o pipe");
        exit(1); // Finalização segura
    }

    while (1)
    {
        line = get_next_line(STDIN_FILENO); // Lê a entrada do usuário
        if (!line)
        {
            perror("Erro ao ler a linha");
            exit(1); // Finalização segura
        }

        // Verifica se a linha corresponde ao limitador
        if (ft_strncmp(line, file->limiter, ft_strlen(line)) == 0 &&
            ft_strlen(line) == ft_strlen(file->limiter))
            break;

        write(file->pipe_fd[1], line, ft_strlen(line)); // Escreve no pipe
        free(line);
    }

    free(line);
    close(file->pipe_fd[1]); // Fecha o lado de escrita do pipe
    return (file->pipe_fd[0]); // Retorna o lado de leitura
}

void	handle_redirection_input(char **cmd_args)
{
	int	fd;
	int	i;

	i = 0;
	fd = -1;
	while (cmd_args[i])
	{
		// EOF
		if (ft_strncmp(cmd_args[i], "<<", 2) == 0)
			here_doc();

		
		if (ft_strncmp(cmd_args[i], "<", 1) == 0 && cmd_args[i + 1])
		{
			if (access(cmd_args[i + 1], F_OK) == -1)
			{
				perror("Arquivo inexistente");
				exit(1);
			}
			fd = open(cmd_args[i + 1], O_RDONLY);
			if (fd < 0)
			{
				perror("open");
				exit(1);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
			// Remove "< file" dos argumentos
			while (cmd_args[i])
			{
				cmd_args[i] = cmd_args[i + 2];
				i++;
			}
			break ;
		}
		i++;
	}
}

void execute_command(char **cmd_args, char **envp) {
	pid_t pid = fork();
	
	if (pid == 0) { // Processo filho
		handle_redirection_input(cmd_args);  // Tratar '<' antes do execve()
		
		if (!cmd_args[0]) {
			perror("Invalid command");
			exit(1);
		}

		execve(cmd_args[0], cmd_args, envp);
		perror("execve");
		exit(127);
	}
	else if (pid > 0) { // Processo pai
		waitpid(pid, NULL, 0);
	}
	else {
		perror("fork");
	}
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
		if (pid == 0)
		{
			dup2(fd_in, STDIN_FILENO);  // Entrada padrão
			dup2(pipe_fd[1], STDOUT_FILENO); // Saída padrão
			close(pipe_fd[0]);
			close(pipe_fd[1]);
			execute_command(file.cmds[i], envp);
		}
		else
		{
			waitpid(pid, NULL, 0);
			close(pipe_fd[1]);
			fd_in = pipe_fd[0];
		}
	}
	int fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out < 0) // Último comando
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
	i = 0;
	while (i < file.cmd_count) // Libera memória
	{
		free(file.cmds[i]);
		i++;
	}
	free(file.cmds);
}

int	main(int argc, char **argv, char **envp)
{
	pipex(argc, argv, envp);
	return (0);
}
