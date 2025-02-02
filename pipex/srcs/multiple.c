/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 19:14:03 by kwillian          #+#    #+#             */
/*   Updated: 2025/02/02 19:04:51 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**init_nodes(char **env)
{
	char	**path;
	int		index;

	path = NULL;
	index = 0;
	while (env && env[index])
	{
		if (ft_strncmp(env[index], "PATH=", 5) == 0)
		{
			path = ft_split(env[index], ':');
			if (!path)
				cleaner_double(path);
			else
				path[0] = path[0] + 5;
			break ;
		}
		index++;
	}
	return (path);
}

void	file_init(t_multip *file, char **envp)
{
	file->argv = NULL;
	file->envp = NULL;
	file->limiter = NULL;
	file->path = NULL;
	file->envp = init_nodes(envp);

	int i = 0;
	while (envp[i])
	{
		printf("\n%s", envp[i]);
		i++;
	}
}

void	file_clean(t_multip *file)
{
	int	i;

	i = 0;
	while (file->argv[i])
	{
		free(file->argv[i]);
		i++;
	}
	free(file->argv);
	free(file->path);
	free(file->envp);
	free(file->limiter);
	exit(1);
}