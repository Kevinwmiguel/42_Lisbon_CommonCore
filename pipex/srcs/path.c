/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:06:35 by kwillian          #+#    #+#             */
/*   Updated: 2025/02/02 19:00:24 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_cleaner(char **paths)
{
	int	i;

	i = 0;
	while (paths && paths[i])
	{
		if (i == 0)
			free(paths[i] - 5);
		else
			free(paths[i]);
		i++;
	}
	if (paths)
		free(paths);
}

void	pick_path2(t_files *file, char **path, int cmd_index, int path_index)
{
	char	*tmp;

	tmp = ft_strjoin(path[path_index], "/");
	if (!tmp)
	{
		path_cleaner(path);
		final_cleaner(file);
		exit(EXIT_FAILURE);
	}
	file->cmds[cmd_index][0] = ft_strjoin(tmp, file->cmds[cmd_index][0]);
	free(tmp);
	if (!file->cmds[cmd_index][0])
	{
		path_cleaner(path);
		final_cleaner(file);
		exit(EXIT_FAILURE);
	}
}

char	**pick_path(char **envp)
{
	char	**path;
	int		index;

	index = 0;
	path = NULL;
	while (envp && envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 5) == 0)
		{
			path = ft_split(envp[index], ':');
			if (!path)
				path_cleaner(path);
			else
				path[0] = path[0] + 5;
			break ;
		}
		index++;
	}
	return (path);
}

void    search_path(t_files *file, char **paths)
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

			if (access(full_path, X_OK) == 0)
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
