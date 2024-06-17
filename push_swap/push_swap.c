/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:00:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/06/17 19:29:38 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // Inclui a definição de t_node
#include <stdio.h>

#include "libft/libft.h" 
# include "printf/ft_printf.h"

int main(int argc, char **argv)
{
    t_node *a = NULL;
    t_node *new_node;
    t_node *b = NULL;

    int i = 1;
    int *data;
    while (i < argc)
    {
        data = (int *)malloc(sizeof(int));
        *data = ft_atoi(argv[i]);
        new_node = ft_lstnew(data);
        ft_lstadd_front(&a, new_node);
        i++;
    }
    // CHAMA ORGANIZADOR
    
    return (0);
}
