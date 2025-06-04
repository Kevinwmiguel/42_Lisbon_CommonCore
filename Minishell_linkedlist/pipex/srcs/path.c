/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 00:06:35 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/01 18:16:24 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

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

void	pick_path2(t_files *file, char **path, int cmd_idx, int path_idx)
{
	char	*tmp;

	tmp = ft_strjoin(path[path_idx], "/");
	if (!tmp)
	{
		path_cleaner(path);
		exit(EXIT_FAILURE);
	}
	file->cmds[cmd_idx][0] = ft_strjoin(tmp, file->cmds[cmd_idx][0]);
	free(tmp);
	if (!file->cmds[cmd_idx][0])
	{
		path_cleaner(path);
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
