/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:47 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/20 20:30:03 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command_path(char *cmd)
{
	char	*paths[3];
	char	*full_path;
	int		i;

	i = 0;
	paths[0] = "/bin/";
	paths[1] = "/usr/bin/";
	paths[2] = NULL;
	while (paths[i])
	{
		full_path = malloc(strlen(paths[i]) + length2(cmd) + 1);
		if (!full_path)
		{
			perror("Erro de malloc");
			exit(1);
		}
		ft_strcpy(full_path, paths[i]);
		ft_strcat(full_path, cmd);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

char	*get_directory_path(char *path)
{
	char	*last_slash;
	char	*dir_path;

	last_slash = ft_strrchr(path, '/');
	if (!last_slash)
		return (NULL);
	dir_path = malloc(last_slash - path + 2);
	if (!dir_path)
	{
		perror("Erro de malloc");
		exit(1);
	}
	ft_strncpy(dir_path, path, last_slash - path + 1);
	dir_path[last_slash - path + 1] = '\0';
	return (dir_path);
}

void	child_one(t_files fd_read, int fd_write, char **cmd, char *file_path)
{
	char	*command_path;
	char	*dir_path;

	dup2(fd_read.infile, STDIN_FILENO);
	dup2(fd_write, STDOUT_FILENO);
	close(fd_read.infile);
	close(fd_write);
	dir_path = get_directory_path(file_path);
	if (ft_strncmp(cmd[0], "ls", 2) == 0)
		cmd = add_file_to_cmd(cmd, file_path);
	command_path = get_command_path(cmd[0]);
	if (!command_path)
	{
		perror("Comando não encontrado");
		free(dir_path);
		exit(1);
	}
	execve(command_path, cmd, fd_read.envp);
	perror("Execve falhou");
	free(command_path);
	free(dir_path);
	exit(1);
}

void	child_two(int fd_read, t_files fd_write, char **cmd)
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
