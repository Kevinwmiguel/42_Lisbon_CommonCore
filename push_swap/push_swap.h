/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:03:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/05 18:17:27 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct node
{
    int number;
    int index;
    int costToPush;
    bool upMedium;
    bool chepeast;
    struct node *target;
    struct node *next;
    struct node *prev;
} t_node;

char *ft_strtok(char *str, const char *delim);
t_node *ft_lstnew2(int number, int idx);
void sa(t_node *original);
void sb(t_node *original);
void ss(t_node *a, t_node *b);
void pa(t_node **a, t_node **b);
void pb(t_node **a, t_node **b);
void ra(t_node **a);
void rb(t_node **b);
void rr(t_node **a, t_node **b);
void rra(t_node **a);
void rrb(t_node **b);
void rrr(t_node **a, t_node **b);
void	ft_lstadd_front2(t_node **lst, t_node *new);
void insert(t_node **a, long int data, int idx);
void process_args(int argc, char *argv[], t_node **a, t_node **b);
void pushT3ona(t_node **a, t_node **b);

#include "libft/libft.h" // Inclui a definição de t_list
# include "printf/ft_printf.h"

#endif