/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:22:41 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/03 00:39:56 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

void	remove_double_right_tokens(t_pipesort *piped, int limiter_idx)
{
	int	i;

	i = limiter_idx - 1;
	while (piped->content[i + 1])
	{
		piped->content[i] = piped->content[i + 1];
		i++;
	}
	piped->content[i] = NULL;
	piped->content[i - 1] = NULL;
}

void	remove_one_right_tokens(t_pipesort *piped, int file_idx)
{
	int	i;

	i = file_idx - 1;
	free(piped->content[i]);
	free(piped->content[i + 1]);
	while (piped->content[i + 2])
	{
		piped->content[i] = piped->content[i + 2];
		i++;
	}
	piped->content[i] = NULL;
}

char	**remove_redirection(char **cmd, int index)
{
	int		count;
	char	**new_cmd;
	int		i;
	int		j;

	j = 0;
	i = 0;
	count = count_args(cmd);
	new_cmd = malloc(sizeof(char *) * (count - 1));
	while (cmd[i])
	{
		if (i == index || i == index + 1)
		{
			free(cmd[i]);
			i++;
			continue ;
		}
		new_cmd[j++] = cmd[i++];
	}
	new_cmd[j] = NULL;
	free(cmd);
	return (new_cmd);
}
