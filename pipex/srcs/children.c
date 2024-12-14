/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:47 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/14 18:14:52 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	length(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	return (i);
}

void	child_one(files fd_read, int fd_write, char **cmd, char *argv)
{
	char	*nova;

	dup2(fd_read.infile, STDIN_FILENO);
	dup2(fd_write, STDOUT_FILENO);
	close(fd_read.infile);
	close(fd_write);
	nova = ft_strjoin("/bin/", cmd[0]);
	if (!nova)
		ft_free_split(nova, "ft_strjoin error");
	if (ft_strncmp(cmd[0], "ls", 3) == 0)
	{
		if (cmd[1] == NULL)
		{
			cmd[1] = argv;
			cmd[2] = NULL;
		}
		else if (cmd[1] != NULL && access(argv , F_OK) == 0)
			cmd[length(cmd)] = argv;
		else
			ft_free_split(nova, "Arquivo nao encontrado");
	}	
	execve(nova, cmd, fd_read.envp);
	perror("Execve: ");
	free(nova);
	exit(1);
}

void	child_two(int fd_read, files fd_write, char **cmd)
{
	char	*nova;

	dup2(fd_read, STDIN_FILENO);
	dup2(fd_write.outfile, STDOUT_FILENO);
	close(fd_read);
	close(fd_write.outfile);
	nova = ft_strjoin("/bin/", cmd[0]);
	if (!nova)
	{
		perror("ft_strjoin: ");
		exit(1);
	}
	execve(nova, cmd, fd_write.envp);
	perror("Execve: ");
	free(nova);
	exit(1);
}
