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

int is_sorted(t_node *a)
{
    while (a != NULL && a->next != NULL)
    {
        if (a->number > a->next->number)
            return 0;
        a = a->next;
    }
    return 1;
}

void simple_sort(t_node **a, t_node **b)
{
    while (!is_sorted(*a))
    {
        if ((*a)->number > (*a)->next->number)
        {
            sa(*a);
            ft_printf("sa\n");
        }
        else
        {
            pb(a, b);
            ft_printf("pb\n");
        }
    }
    while (*b != NULL)
    {
        pa(a, b);
        ft_printf("pa\n");
    }
}

void free_list(t_node *head)
{
    t_node *current = head;
    t_node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

int main(int argc, char **argv)
{
    t_node *a = NULL;
    t_node *new_node;
    t_node *b = NULL;
    int i;

    i = 1;
    while (i < argc)
    {
        int *data = (int *)malloc(sizeof(int));
        if (data == NULL)
        {
            ft_printf("Erro de alocação de memória\n");
            return (1);
        }
        *data = ft_atoi(argv[i]);
        new_node = ft_lstnew(data);
        if (new_node == NULL)
        {
            ft_printf("Erro de criação de novo nó\n");
            free(data);
            return (1);
        }
        ft_lstadd_front(&a, new_node);
        i++;
    }
    // Chama o organizador
    simple_sort(&a, &b);
    // Libera memória
    free_list(a);
    free_list(b);
    return (0);
}