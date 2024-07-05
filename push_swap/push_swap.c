/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:00:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/05 18:52:34 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // Inclui a definição de t_node
#include <stdio.h>

#include "libft/libft.h" 
# include "printf/ft_printf.h"

t_node *mymin(t_node *b)
{
    long int temp;
    t_node *min_t_node;

    if(!b)
        return (NULL);
    temp = LONG_MAX;
    while (b)
    {
        if (b->number < temp)
        {
            temp = b->number;
            min_t_node = b;
        }
        b = b->next;
    }
    return (min_t_node);
}

int mymax(t_node *b)
{
    int temp;
    
    temp = b->number;
    while (b != NULL)
    {
        if (b->number < b->next->number)
            sb(b);
    }
    return temp;
}

int is_sorted(t_node *lst)
{
    while (lst != NULL && lst->next != NULL)
    {
        if (lst->number > lst->next->number)
            return (0);
        lst = lst->next;
    }
    return (1);
}
void pushT3ona(t_node **a, t_node **b)
{
    int elements = 0;
    t_node *temp;
    
    // Contar os elementos na pilha a
    pb(a, b);
    pb(a, b);
    temp = *a;
    while(temp != NULL)
    {
        elements++;
        temp = temp->next;
    }
    //VERIFICAR ORGANIZAÇAO EM B
    //maxmin_max();
    // Mover elementos de a para b até que a tenha apenas 3 elementos
    while(elements > 3)
    {
        pb(a, b);  // Supondo que pb(&a, &b) move o topo de a para b   
        elements--;
    }
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
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return 0;
    t_node *a = NULL;
    t_node *b = NULL;
    //REcebe valores, coloca eles dentro e passa 2 valores para B
    process_args(argc, argv , &a, &b);
    // Aqui devemos chamar identificadores de maior e menor e passar todos o elementos para B ate 3 sobrar 3 em A

    free_list(a);
    free_list(b);
    return 0;
}
