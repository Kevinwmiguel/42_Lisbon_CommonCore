/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:44:56 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/01 18:15:08 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

size_t	length2(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != '\0')
		i++;
	return (i);
}

size_t	length(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
		i++;
	return (i);
}

int	ft_lstsize_pipesort(t_pipesort *lst)
{
	int			i;
	t_pipesort	*list;

	i = 0;
	list = lst;
	while (list->next != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int	find_input_file_index(char **content, int i)
{
	while (content[i])
	{
		if (ft_strncmp(content[i], "<", 1) == 0)
		{
			if (content[i + 1])
				return (i + 1);
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}
