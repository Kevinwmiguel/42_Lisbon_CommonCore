/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2025/02/10 13:43:14 by kwillian         ###   ########.fr       */
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
	file->envp = malloc(sizeof(char *) * (length(envp) + 1));
	file->envp = envp;
	file->cmd_count = argc - 2; // 3 para o output do pipex
	file->cmds = malloc(sizeof(char **) * file->cmd_count);
	while (++i < file->cmd_count)
		file->cmds[i] = ft_split(argv[2 + i], ' ');
}

void	pipex(int argc, char **argv, char **envp)
{
	t_files	*file;
	int		fd_in;
	pid_t	pid;
	int		i;
	char	**paths;
	int		fd_out;

	file = malloc(sizeof(t_files));
	init_func(file, envp, argv, argc);
	paths = pick_path(envp);
	search_path(file, paths);
	fd_in = check_infile(argv[1]);
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
			dup2(fd_in, STDIN_FILENO);
			dup2(file->pipe_fd[1], STDOUT_FILENO);
			close(file->pipe_fd[0]);
			close(file->pipe_fd[1]);
			close(fd_in);
			execute_command(file->cmds[i], envp);
			exit(1);
		}
		else
		{
			waitpid(pid, NULL, 0);
			close(file->pipe_fd[1]);
			close(fd_in);
			fd_in = file->pipe_fd[0];
		}
		i++;
	}
	if (argc > 2 && !is_command(argv[argc - 1]))
	{
		fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd_out < 0)
		{
			perror("Erro ao abrir o arquivo de saída");
			fd_out = STDOUT_FILENO;
		}
	}
	else
	{
		fd_out = STDOUT_FILENO;
	}
	if (is_command(argv[argc - 1]))
	{
		fd_out = STDOUT_FILENO;
		dup2(fd_in, STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		close(fd_in);
		execute_command(file->cmds[i], envp);
	}
	else
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(fd_in, STDIN_FILENO);
			dup2(fd_out, STDOUT_FILENO);
			close(fd_in);
			close(fd_out);
			execute_command(file->cmds[i], envp);
			exit(1);
		}
		else
		{
			waitpid(pid, NULL, 0);
			close(fd_in);
			if (fd_out != STDOUT_FILENO)
				close(fd_out);
		}
	}
	free_split((*file->cmds));
}
