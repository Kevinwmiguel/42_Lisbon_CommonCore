/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/22 03:31:33 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_node_to_list(t_list **new_list, t_list **last, t_list *new_node)
{
	if (*last == NULL)
		*new_list = new_node;
	else
		(*last)->next = new_node;
	*last = new_node;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*last;
	void	*content;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	last = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		add_node_to_list(&new_list, &last, new_node);
		lst = lst->next;
	}
	return (new_list);
}
