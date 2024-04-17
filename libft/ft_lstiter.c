/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:19:31 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/17 17:10:54 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    t_list *newlist;

    newlist = lst;
    if(!newlist)
        return ;
    while (newlist->next)
    {
        f(newlist->content);
        newlist = newlist->next;
    }
    if (newlist)
        f(newlist->content);
}

static void print_int(void *ptr) {
    printf("%d\n", *((int *)ptr));
}

int main() {
    t_list *node = NULL;

    int a = 5, b = 10, c = 20;

    t_list *na = ft_lstnew(&a);
    t_list *nb = ft_lstnew(&b);
    t_list *nc = ft_lstnew(&c);

    ft_lstadd_front(&node, na);
    ft_lstadd_front(&node, nb);
    ft_lstadd_front(&node, nc);
    
    ft_lstiter(node, print_int);

    ft_lstclear(&node, free);
    node = NULL;

    return 0;
}