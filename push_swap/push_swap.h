/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:03:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/31 04:53:20 by kwillian         ###   ########.fr       */
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
void	simple_sort(t_node **a, t_node **b);
void	simple_sort_three(t_node **a);
void	sa(t_node *original, char c);
void	sb(t_node *original, char c);
void	ss(t_node *a, t_node *b, char c);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a, char c);
void	rb(t_node **b, char c);
void	rr(t_node **a, t_node **b, char c);
void	free_list(t_node *head);
void	rra(t_node **a, char c);
t_node*	get_cheapest(t_node *stack);
void	rrb(t_node **b, char c);
void	rrr(t_node **a, t_node **b, char c);
void	ft_lstadd_front2(t_node **lst, t_node *new);
void	insert(t_node **a, long int data, int idx);
void	process_args(int argc, char *argv[], t_node **a, t_node **b);
void	push_3_on_a(t_node **a, t_node **b);
void	free_list(t_node *head);
int		stack_len(t_node *stack);
bool	check_errors(int argc, char *argv[]);
void	free_split_args(char **args);
bool	is_sorted(t_node *lst);
void	set_target_a(t_node *a, t_node *b);
void	cost_checker(t_node *a, t_node *b);
void	cheaper_one(t_node *lst);
void	move_cheapest(t_node **a, t_node **b);
void	sort_stack_b(t_node **b);
void	printa(t_node *a);
void	printb(t_node *b);
bool	is_sorted_b(t_node *lst);
int	is_sorted_desc(t_node *stack);
void	push_all_to_b(t_node **a, t_node **b);
void	move_a_to_b(t_node **a, t_node **b);
void	sort_stks(t_node **a, t_node **b);
void	min_on_top(t_node **stack);
t_node	*find_max(t_node *a,t_node *b);
t_node	*find_min(t_node *a,t_node *b);
void	current_index(t_node *stack);
void	move_b_to_a(t_node **a, t_node **b);
t_node* find_best_target(t_node *a, t_node *b);
void	create_index(t_node *a);
void prep_push(t_node **stack, t_node *cheap, char c, t_node **other);
void prep_push_combined(t_node **a, t_node **b, t_node *cheap, char c, bool is_double_rotation);

#endif