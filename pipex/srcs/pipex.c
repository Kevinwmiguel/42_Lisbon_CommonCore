/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2025/02/10 23:12:10 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_command(char **cmd_args, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		handle_redirection_input(cmd_args);
		if (!cmd_args[0])
		{
			perror("Invalid command");
			exit(1);
		}
		execve(cmd_args[0], cmd_args, envp);
		perror("execve");
		exit(1);
	}
	else if (pid > 0)
		waitpid(pid, NULL, 0);
	else
		perror("fork");
}

void	init_func(t_files *file, char **envp, char **argv, int argc)
{
	int	i;

	i = -1;
	file->paths = malloc(sizeof(char *) * 1);
	file->envp = malloc(sizeof(char *) * (length(envp) + 1));
	file->envp = envp;
	file->cmd_count = argc - 3; // 3 para o output do pipex
	file->cmds = malloc(sizeof(char **) * file->cmd_count);
	while (++i < file->cmd_count)
		file->cmds[i] = ft_split(argv[2 + i], ' ');
}

void	pipex(int argc, char **argv, char **envp)
{
	t_files		*file;
	pid_t		pid;
	int			i;

	file = malloc(sizeof(t_files));
	init_func(file, envp, argv, argc);
	file->paths = pick_path(envp);
	search_path(file, file->paths);
	file->infile = check_infile(argv[1]);

	i = 0;
	while (i < file->cmd_count - 1)
	{
		if (pipe(file->pipe_fd) == -1)
			exit(printf("Erro ao criar o pipe"));
		pid = fork();
		if (pid == -1)
			exit(printf("Erro ao criar o processo"));
		if (pid == 0)
		{
			dup2(file->infile, STDIN_FILENO);
			dup2(file->pipe_fd[1], STDOUT_FILENO);
			close(file->pipe_fd[0]);
			close(file->pipe_fd[1]);
			close(file->infile);
			execute_command(file->cmds[i], envp);
			exit(1);
		}
		else
		{
			waitpid(pid, NULL, 0);
			close(file->pipe_fd[1]);
			close(file->infile);
			file->infile = file->pipe_fd[0];
		}
		i++;
	}

	if (argc > 2 && !is_command(argv[argc - 1]))
	{
		file->outfile = open(argv[argc - 1], O_WRONLY \
		| O_CREAT | O_TRUNC, 0644);
		if (file->outfile < 0)
		{
			perror("Erro ao abrir o arquivo de saída");
			file->outfile = STDOUT_FILENO;
		}
	}
	else
	{
		file->outfile = STDOUT_FILENO;
	}

	if (is_command(argv[argc - 1]))
	{
		file->outfile = STDOUT_FILENO;
		dup2(file->infile, STDIN_FILENO);
		dup2(file->outfile, STDOUT_FILENO);
		close(file->infile);
		execute_command(file->cmds[i], envp);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(file->infile, STDIN_FILENO);
			dup2(file->outfile, STDOUT_FILENO);
			close(file->infile);
			close(file->outfile);
			execute_command(file->cmds[i], envp);
			exit(1);
		}
		else
		{
			waitpid(pid, NULL, 0);
			close(file->infile);
			if (file->outfile != STDOUT_FILENO)
				close(file->outfile);
		}
	}
	free_split((*file->cmds));
}
