/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 16:02:20 by thiago-camp       #+#    #+#             */
/*   Updated: 2025/06/01 18:28:30 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

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

void	init_pipexinfo(t_pipexinfo *px, t_pipesort *piped)
{
	px->fd_in = -1;
	px->i = 0;
	px->pipe_counts = ft_lstsize_pipesort(piped);
}

void	inform_path_error(void)
{
	exit(1);
}
