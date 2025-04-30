/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2025/04/30 17:55:57 by kwillian         ###   ########.fr       */
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
	printf("%s %s TEM AQUI \n", cmd_args[0], cmd_args[1]);
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
	int		fd[2];
	int		fd_in = 0; // começa com stdin

	i = 0;
	flag = ft_lstsize_pipesort(piped);
	printf("VALOR DE FLAG %d \n", flag);
	while (i < flag)
	{
		if (i != flag - 1)
			pipe(fd);

		pid = fork();
		if (pid == 0)
		{
			if (i != 0)
			{
				dup2(fd_in, STDIN_FILENO);
				close(fd_in);
			}
			if (i != flag - 1)
			{
				dup2(fd[1], STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
			}
			execute_command(file->cmds[i], file->envp, piped);
			exit(1); // garantir que o filho saia
		}
		else
		{
			if (i != 0)
				close(fd_in); // fechar entrada anterior

			if (i != flag - 1)
			{
				close(fd[1]);       // fechar escrita do pipe
				fd_in = fd[0];      // salvar leitura para próximo
			}
			waitpid(pid, NULL, 0);
			piped = piped->next;
			i++;
		}
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

	file = malloc(sizeof(t_files));
	init_func(file, utils->envr, piped, argc);
	file->paths = path;
	//search_path(file, file->paths);
	//checar se tem redirection aqui ou a file
	//handle_redirection_input(piped);
	//file->infile = check_infile(argv[1]);
	main3pipex(file, piped);
}
