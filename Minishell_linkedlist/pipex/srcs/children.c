/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:47 by kwillian          #+#    #+#             */
/*   Updated: 2025/04/01 22:37:42 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

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
