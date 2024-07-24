/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:03:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/24 18:56:00 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h" // Inclui a definição de t_list
# include "printf/ft_printf.h"

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct node
{
	int			number;
	int			index;
	int			cost_to_push;
	bool		upmedium;
	bool		cheapest;
	struct node	*target;
	struct node	*next;
	struct node	*prev;
}	t_node;

t_node	*ft_lstnew2(int number, int idx);
void	sa(t_node *original);
void	sb(t_node *original);
void	ss(t_node *a, t_node *b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	free_list(t_node *head);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);
void	ft_lstadd_front2(t_node **lst, t_node *new);
void	insert(t_node **a, long int data, int idx);
void	process_args(int argc, char *argv[], t_node **a, t_node **b);
void	push_3_on_a(t_node **a, t_node **b);
void	free_list(t_node *head);
int		stack_len(t_node *stack);
void	min_on_top(t_node **a);
bool	check_errors(int argc, char *argv[]);
void	free_split_args(char **args);
bool	is_sorted(t_node *lst);
void	set_target_a(t_node *a, t_node *b);
void	cost_checker(t_node *a, t_node *b);
void	cheaper_one(t_node *lst);
void	move_cheapest(t_node **a, t_node **b);
void	sort_stack_b(t_node **b);
void	simple_sort_five(t_node **a, t_node **b);
void	simple_sort_three(t_node **a);
void	printa(t_node *a);

#endif