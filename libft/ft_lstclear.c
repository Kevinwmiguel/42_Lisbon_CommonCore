/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:06:49 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/17 18:58:22 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	if (!temp || !del)
		return ;
	while (temp)
	{
		temp2 = temp->next;
		ft_lstdelone(temp, del);
		temp = temp2;
	}
	temp = NULL;
}
