/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:44:56 by kwillian          #+#    #+#             */
/*   Updated: 2025/04/28 14:50:51 by kwillian         ###   ########.fr       */
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
	int		i;
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
