/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 20:36:37 by kwillian          #+#    #+#             */
/*   Updated: 2024/06/17 19:29:35 by kwillian         ###   ########.fr       */
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
}

void sb(t_node *original)
{
    if (original == NULL || original->next == NULL)
        return;
    int temp;
    
    temp = original->number;
    original->number = original->next->number;
    original->next->number = temp;
}

void ss(t_node *a, t_node *b)
{   
    sa(a);
    sb(b);
}

void pa(t_node **a, t_node **b)
{
    if (*b == NULL) // Se b está vazio, nada a fazer
        return;

    t_node *temp = *b; // Guardar o topo de b
    *b = (*b)->next; // Atualizar o topo de b

    if (*b != NULL) // Se b não está vazio depois da atualização
        (*b)->prev = NULL;

    ft_lstadd_front(a, temp); // Adicionar temp no topo de a

    temp->next = *a; // Atualizar os ponteiros de temp
    temp->prev = NULL;
    if (*a != NULL)
        (*a)->prev = temp;
    *a = temp; // Atualizar o topo de a
    return;
}

void pb(t_node **a, t_node **b)
{
    if (*a == NULL)
        return;
    
    t_node *hold = a; // guarda o topo de a
    *a = (*a)->next;

    if (*a != NULL)
        (*a)->prev = NULL;
    ft_lstadd_front(b, hold);
    
    
    hold->next = *b;
    hold->prev = NULL;
    if (*b != NULL)
        (*b)->prev = hold;
    *b = hold;
}

void ra(t_node **a)
{
    if (*a == NULL || (*a)->next == NULL)
        return;
    t_node *temp = a;
    t_node *current = a;
    while(current->next != NULL)
    {
        current = current->next;
    }
    *a = (*a)->next;
    (*a)->prev = NULL;
    current->next = temp;
    temp->prev = current;
    temp->next = NULL;
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
}

void rr(t_node **a, t_node **b)
{
    ra(a);
    rb(b);
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
}

void rrr(t_node **a, t_node **b)
{
    rra(a);
    rrb(b);
}