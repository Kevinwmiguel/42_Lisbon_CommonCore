/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:43:19 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/17 16:06:28 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
	{
		return ;
	}
	if (del)
		del(lst->content);
	free(lst);
}
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int *num = (int *)malloc(sizeof(int));
//     *num = 42;
//     t_list *node = ft_lstnew(num);

//     printf("content : %d\n", *((int *)node->content));

//     ft_lstdelone(node, free);
//     // VAI DAR SEGMENTATION FAULT AQUI NA HORA DA DEFESA E ´E NORMAL! 
//     printf("node after: : %d\n", *((int *)node->content));

//     return 0;
// }