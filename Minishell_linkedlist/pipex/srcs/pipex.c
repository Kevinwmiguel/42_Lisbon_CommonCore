/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2025/04/29 14:00:22 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

void	execute_command(char **cmd_args, char **envp, t_pipesort *piped)
{
	char	*fullpath;

	fullpath = "/bin/";
	//handle_redirection_input(cmd_args);
	if (!cmd_args[0])
	{
		perror("Invalid command");
		exit(1);
	}
	fullpath = ft_strjoin(fullpath, piped->content[0]);
	execve(fullpath , cmd_args, envp);
	perror("execve");
	exit(1);
}

void	dup_process2(t_files *file, int i, t_pipesort *piped)
{
	dup2(file->infile, STDIN_FILENO);
	dup2(file->outfile, STDOUT_FILENO);
	close(file->infile);
	close(file->outfile);
	execute_command(file->cmds[i], file->envp, piped);
	exit(1);
}

void	main3pipex(t_files *file, t_pipesort *piped)
{
	pid_t	pid;
	int		i;
	int		flag;
	int fd[2];
	int fd_anterior[2];

	i = 0;
	flag = ft_lstsize_pipesort(piped);
	while (i < flag)
	{
		//SE N FOR O ULTIMO crio um pipe
		if (i != flag - 1)
			pipe(fd);

		pid = fork();
		if (pid == 0) // child
		{
			if (i == 0) // primeiro comando
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			else if (i == flag - 1) // último comando
			{
				dup2(fd_anterior[0], STDIN_FILENO);
				close(fd_anterior[0]);
			}
			else // comandos do meio
			{
				dup2(fd_anterior[0], STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				close(fd_anterior[0]);
				close(fd[0]);
				close(fd[1]);
			}
			execute_command(file->cmds[i], file->envp, piped);
		}
		else // parent
		{
			waitpid(pid, NULL, 0);
			if (i != 0)
				close(fd_anterior[0]);
			if (i != flag - 1)
				fd_anterior[0] = fd[0];
		}
		i++;
	}
	free_split((*file->cmds));
}


void	init_func(t_files *file, char **envp, char **argv, int argc)
{
	int	i;

	i = 0;
	file->paths = malloc(sizeof(char *) * 1);
	file->envp = malloc(sizeof(char *) * (length(envp) + 1));
	file->envp = envp;
	file->cmd_count = argc;
	file->cmds = malloc(sizeof(char **) * file->cmd_count);
	while (i < file->cmd_count)
	{
		file->cmds[i] = argv;
		i++;
	}
}

void	pipex(int argc, t_pipesort *piped, t_shell *utils, char *path)
{
	t_files		*file;

	file = malloc(sizeof(t_files));
	init_func(file, utils->envr, piped->content, argc);
	file->paths = path;
	//search_path(file, file->paths);
	//checar se tem redirection aqui ou a file
	//handle_redirection_input(piped);
	//file->infile = check_infile(argv[1]);
	main3pipex(file, piped);
}
