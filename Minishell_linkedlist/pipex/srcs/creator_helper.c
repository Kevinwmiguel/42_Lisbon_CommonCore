/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creator_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 19:16:18 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/03 00:41:37 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

void	create_empty_output_file(char *type, char *filename)
{
	int	fd;

	if (ft_strncmp(type, ">>", 2) == 0)
		fd = open(filename, O_WRONLY | O_CREAT, 0644);
	else
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("open");
		exit(1);
	}
	close(fd);
}

void	remove_redir_pair(t_pipesort *piped, int index)
{
	int	j;

	j = index;
	while (piped->content[j + 2])
	{
		piped->content[j] = piped->content[j + 2];
		j++;
	}
	piped->content[j] = NULL;
	piped->content[j + 1] = NULL;
}

void	remove_last_redir_pair(t_pipesort *piped, int index)
{
	int	j;

	j = index;
	while (piped->content[j + 2])
	{
		piped->content[j] = piped->content[j + 2];
		j++;
	}
	piped->content[j] = NULL;
	piped->content[j + 1] = NULL;
}

void	remove_all_output_redirs(t_pipesort *piped, int last_index)
{
	int	i;

	i = 0;
	while (piped->content[i])
	{
		if ((i != last_index) && \
			(ft_strncmp(piped->content[i], ">", 2) == 0 || \
			ft_strncmp(piped->content[i], ">>", 3) == 0) && \
				piped->content[i + 1])
		{
			create_empty_output_file(piped->content[i], piped->content[i + 1]);
			remove_redir_pair(piped, i);
			continue ;
		}
		i++;
	}
	remove_last_redir_pair(piped, last_index);
}
