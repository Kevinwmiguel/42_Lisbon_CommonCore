/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:36:37 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/02 04:00:28 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node *original)
{

    if (original == NULL || original->next == NULL)
        return;
    int temp;
    
    temp = original->number;
    original->number = original->next->number;
    original->next->number = temp;
    ft_printf("sa\n");
}

void sb(t_node *original)
{
    if (original == NULL || original->next == NULL)
        return;
    int temp;
    
    temp = original->number;
    original->number = original->next->number;
    original->next->number = temp;
    ft_printf("sb\n");
}

void ss(t_node *a, t_node *b)
{   
    sa(a);
    sb(b);
    ft_printf("ss\n");
}

void pa(t_node **a, t_node **b) {
    
    if (*b == NULL) return;

    t_node *hold = *b;
    *b = (*b)->next;

    if (*b != NULL) {
        (*b)->prev = NULL;
    }
    hold->next = NULL;
    hold->prev = NULL;
    ft_lstadd_front2(a, hold);
    ft_printf("pa\n");
}

void pb(t_node **a, t_node **b) {
    
    if (*a == NULL) return;

    t_node *hold = *a;
    *a = (*a)->next;

    if (*a != NULL) {
        (*a)->prev = NULL;
    }
    hold->next = NULL;
    hold->prev = NULL;
    ft_lstadd_front2(b, hold);
    ft_printf("pb\n");
}

void ra(t_node **a)
{
    if (*a == NULL || (*a)->next == NULL)
        return;
    t_node *temp = *a;
    t_node *current = *a;
    while(current->next != NULL)
    {
        current = current->next;
    }
    *a = (*a)->next;
    (*a)->prev = NULL;
    current->next = temp;
    temp->prev = current;
    temp->next = NULL;
    ft_printf("ra\n");
}

void rb(t_node **b)
{
    if (*b == NULL || (*b)->next == NULL)
        return;

    t_node *temp = *b; // Guardar o topo de b
    *b = (*b)->next; // Atualizar o topo de b
    (*b)->prev = NULL;

    t_node *current = *b;
    while(current->next != NULL) // Encontrar o último elemento
    {
        current = current->next;
    }

    current->next = temp; // Mover temp para o final
    temp->prev = current;
    temp->next = NULL;
    ft_printf("rb\n");
}

void rr(t_node **a, t_node **b)
{
    ra(a);
    rb(b);
    ft_printf("rr\n");
}

void rra(t_node **a)
{
    if (*a == NULL || (*a)->next == NULL)
        return;

    t_node *current = *a;
    while(current->next != NULL) // Encontrar o último elemento
    {
        current = current->next;
    }

    current->prev->next = NULL; // Desconectar o último elemento
    current->prev = NULL;
    current->next = *a;
    (*a)->prev = current;
    *a = current; // Atualizar o topo de a
    ft_printf("rra\n");
}

void rrb(t_node **b)
{
    if (*b == NULL || (*b)->next == NULL)
        return;

    t_node *current = *b;
    while(current->next != NULL) // Encontrar o último elemento
    {
        current = current->next;
    }

    current->prev->next = NULL; // Desconectar o último elemento
    current->prev = NULL;
    current->next = *b;
    (*b)->prev = current;
    *b = current; // Atualizar o topo de b
    ft_printf("rrb\n");
}

void rrr(t_node **a, t_node **b)
{
    rra(a);
    rrb(b);
    ft_printf("rrr\n");
}