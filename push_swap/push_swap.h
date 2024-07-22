/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:03:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/22 18:54:40 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <limits.h>
# include <stdbool.h>

typedef struct node
{
    int number;
    int index;
    int costToPush;
    bool upMedium;
    bool cheapest;
    struct node *target;
    struct node *next;
    struct node *prev;
} t_node;

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
void ft_lstadd_front2(t_node **lst, t_node *new);
void insert(t_node **a, long int data, int idx);
void process_args(int argc, char *argv[], t_node **a, t_node **b);
void pushT3ona(t_node **a, t_node **b);
void free_list(t_node *head);
int stack_len(t_node *stack);
void min_on_top(t_node **a);
bool checkErrors(int argc, char *argv[]);
void free_split_args(char **args);
bool is_sorted(t_node *lst);
void set_target_a(t_node *a, t_node *b);
void cost_checker(t_node *a, t_node *b);
void cheaperONE(t_node *lst);
void move_cheapest(t_node **a, t_node **b);

# include "libft/libft.h" // Inclui a definição de t_list
# include "printf/ft_printf.h"

#endif