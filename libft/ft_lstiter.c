/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:19:31 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/17 17:29:29 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*newlist;

	newlist = lst;
	if (!newlist)
		return ;
	while (newlist->next)
	{
		f(newlist->content);
		newlist = newlist->next;
	}
	if (newlist)
		f(newlist->content);
}
// #include <stdio.h>
//
// static void print_int(void *ptr) {
//     printf("%d\n", *((int *)ptr));
// }
//
// int main() {
//     t_list *node = NULL;
//     int a = 5, b = 10, c = 20;
//     // Alocando espaço e copiando os valores de 'a', 'b' e 'c'
//     int *copy_a = malloc(sizeof(int));
//     int *copy_b = malloc(sizeof(int));
//     int *copy_c = malloc(sizeof(int));
//     if (!copy_a || !copy_b || !copy_c) {
//         // Tratamento de erro se a alocação de memória falhar
//         fprintf(stderr, "Erro de alocação de memória\n");
//         exit(1);
//     }
//     *copy_a = a;
//     *copy_b = b;
//     *copy_c = c;  
//     t_list *na = ft_lstnew(&copy_a);
//     t_list *nb = ft_lstnew(&copy_b);
//     t_list *nc = ft_lstnew(&copy_c);
//     ft_lstadd_front(&node, na);
//     ft_lstadd_front(&node, nb);
//     ft_lstadd_front(&node, nc); 
//     ft_lstiter(node, print_int);
//     return 0;
// }
