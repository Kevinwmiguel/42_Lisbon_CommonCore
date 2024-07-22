/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:00:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/22 19:03:19 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // Inclui a definição de t_node
#include <stdio.h>

#include "libft/libft.h" 
# include "printf/ft_printf.h"

bool is_sorted(t_node *lst)
{
    while (lst != NULL && lst->next != NULL)
    {
        if (lst->number > lst->next->number)
            return (0);
        lst = lst->next;
    }
    return (1);
}

bool is_sorted_b(t_node *lst)
{
    while (lst != NULL && lst->next != NULL)
    {
        if (lst->number < lst->next->number)
            return (0);
        lst = lst->next;
    }
    return (1);
}

void move_cheapest(t_node **a, t_node **b) {
    cost_checker(*a, *b);
    cheaperONE(*a);
    cheaperONE(*b);

    t_node *current = *a;
    while (current != NULL) {
        if (current->cheapest) {
            pa(a, b);
            return;
        }
        current = current->next;
    }

    current = *b;
    while (current != NULL) {
        if (current->cheapest) {
            pb(a, b);
            return;
        }
        current = current->next;
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

void sort_stack_b(t_node **b) {
    if (*b == NULL || (*b)->next == NULL) return;

    t_node *current;
    int swapped;

    do {
        swapped = 0;
        current = *b;

        while (current->next != NULL) {
            if (current->number < current->next->number) {
                int temp = current->number;
                current->number = current->next->number;
                current->next->number = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
}

int is_sorted_desc(t_node *stack) {
    if (!stack) return 1;

    while (stack->next) {
        if (stack->number < stack->next->number)
            return 0;
        stack = stack->next;
    }
    return 1;
}

void pushT3ona(t_node **a, t_node **b) {
    // Mover todos os elementos de a para b
    while (*a != NULL) {
        pb(a, b);
    }

    // Ordenar b em ordem decrescente
    sort_stack_b(b);

    // Mover elementos de volta para a em ordem crescente
    while (*b != NULL) {
        pa(a, b);
    }

    // Ordenar a em ordem crescente usando bubble sort
    t_node *current;
    int swapped;

    do {
        swapped = 0;
        current = *a;

        while (current->next != NULL)
        {
            if (current->number > current->next->number)
            {
                int temp = current->number;
                current->number = current->next->number;
                current->next->number = temp;
                swapped = 1;
            }
            current = current->next;
        }
    } while (swapped);
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

int main(int argc, char *argv[])
{
    t_node *a = NULL;
    t_node *b = NULL;

    if (argc < 2)
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    if (!checkErrors(argc, argv))
    {
        ft_putstr_fd("Error\n", 2);
        return (1);
    }
    process_args(argc, argv, &a, &b);
    // stack_sort_ultimate(&a, &b);
    free_list(a);
    free_list(b);
    return (0);
}
