/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2025/05/24 20:42:27 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

char	*checker_path(t_pipesort *piped, char **paths, char *tmp)
{
	char	*fullpath;
	int		i;

	i = 0;
	fullpath = NULL;
	while (paths && paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		fullpath = ft_strjoin(tmp, piped->content[0]);
		free(tmp);
		if (access(fullpath, X_OK) == 0)
			break ;
		free(fullpath);
		fullpath = NULL;
		i++;
	}
	return (fullpath);
}

void	inform_path_error()
{
	exit(1);
}

void	execute_command(char **cmd_args, char **envp, t_pipesort *piped, t_shell *utils)
{
	char	*fullpath;
	int		flag;
	char	**paths;
	char	*tmp;

	tmp = NULL;
	paths = pick_path(envp);
	flag = builtins(piped->content[0], utils, -1);
	printf("flag %d\n", flag);
	if (!cmd_args[0])
	{
		perror("Invalid command");
		exit(1);
	}
	fullpath = checker_path(piped, paths, tmp);
	path_cleaner(paths);
	if (!fullpath)
		inform_path_error();
	if (flag == 0)
	{
		execve(fullpath , cmd_args, envp);
		perror("execve");
	}
	else
	{
		if (builtins(piped->content[0], utils, -1))
		exec_builtin(builtins(piped->content[0], utils, -1), piped->content, 
		 utils->envr, utils); // EDITAR CONDICOES
		exit(1);
	}
	exit(1);
}

void process_and_execute(int pwd_storage_fd, int outfd, char **cmd_args, char **envp, t_pipesort *piped, t_shell *utils)
{
    char buffer[1024];
    ssize_t nbytes;

    if (pwd_storage_fd > 0)
    {
        dup2(pwd_storage_fd, STDIN_FILENO);
        dup2(outfd, STDOUT_FILENO);

        while ((nbytes = read(pwd_storage_fd, buffer, sizeof(buffer))) > 0)
        {
            write(STDOUT_FILENO, buffer, nbytes);
        }

        execute_command(cmd_args, envp, piped, utils);
    }
}

void	main3pipex(t_files *file, t_pipesort *piped, t_shell *utils)
{
	pid_t	pid;
	int		i;
	int		flag;
	int		fd[2];
	int		fd_in;

	fd_in = 0;
	i = 0;
	flag = ft_lstsize_pipesort(piped);
	while (i < flag)
	{
		if (i != flag - 1)
			pipe(fd);

		pid = fork();
		if (pid == 0)
		{
			if (utils->pipe_bridge->pwd_storage > 0)
			{
				process_and_execute(utils->pipe_bridge->pwd_storage, piped->outfd, file->cmds[i], file->envp, piped, utils);
			}
			else if (piped->heredoc_fd > 0)
				dup2(piped->heredoc_fd, STDIN_FILENO);
			else if (i != 0)
				dup2(fd_in, STDIN_FILENO);
			// SAÍDA
			if (utils->pipe_bridge->pwd_storage > 0)
				dup2(piped->outfd, STDOUT_FILENO);
			if (piped->outfd > 0)
				dup2(piped->outfd, STDOUT_FILENO);
			else if (i != flag - 1)
				dup2(fd[1], STDOUT_FILENO);
			// FECHAMENTOS
			if (piped->heredoc_fd > 0)
				close(piped->heredoc_fd);
			if (utils->pipe_bridge->pwd_storage > 0)
				close(utils->pipe_bridge->pwd_storage);
			if (i != 0)
				close(fd_in);
			if (i != flag - 1)
			{
				close(fd[0]);
				close(fd[1]);
			}
			execute_command(file->cmds[i], file->envp, piped, utils);
			exit(1);
		}
		else
		{
			// if (utils->pipe_bridge->pwd_storage > 0)
			// 	close(utils->pipe_bridge->pwd_storage);
			if (i != 0)
				close(fd_in);
			if (i != flag - 1)
			{
				close(fd[1]);
				fd_in = fd[0];
			}
			waitpid(pid, NULL, 0);
			piped = piped->next;
		}
		i++;
	}
}

void	init_func(t_files *file, char **envp, t_pipesort *piped, int argc)
{
	int			i;
	t_pipesort	*tmp;

	i = 0;
	tmp = piped;

	file->paths = malloc(sizeof(char *) * 1);
	file->envp = malloc(sizeof(char *) * (length(envp) + 1));
	if (!file->envp)
		return ;
	file->envp = envp;

	file->cmd_count = argc;
	file->cmds = malloc(sizeof(char **) * file->cmd_count);
	if (!file->cmds)
		return ;

	i = 0;
	while (i < file->cmd_count)
	{
		file->cmds[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
}

void	pipex(int argc, t_pipesort *piped, t_shell *utils, char *path)
{
	t_files		*file;
	t_pipesort	*head;

	piped->outfd = 0;
	file = malloc(sizeof(t_files));
	init_func(file, utils->envr, piped, argc);
	file->paths = path;
	head = piped;

	while (piped->content)
	{
		handle_redirection_left_input(piped);
		handle_redirection_right_input(piped);
		piped = piped->next;
	}
	piped = head;
	main3pipex(file, piped, utils);
}
