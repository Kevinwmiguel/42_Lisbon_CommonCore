/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:02:08 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/16 20:09:34 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

// static void print_list(t_list *lst) {
//     while (lst != NULL) {
//         printf("%d -> ", *((int *)lst->content));
//         lst = lst->next;
//     }
//     printf("NULL\n");
// }
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
}

// int main() {
//     t_list *lst = NULL;

//     // BOtando na listaaaa
//     int a = 10, b = 20, c = 10, d = 70;
//     ft_lstadd_back(&lst, ft_lstnew(&a));
//     ft_lstadd_back(&lst, ft_lstnew(&b));
//     ft_lstadd_back(&lst, ft_lstnew(&c));
//     ft_lstadd_back(&lst, ft_lstnew(&d));
//     printf("Lista: ");
//     print_list(lst);
//     return 0;
// }
