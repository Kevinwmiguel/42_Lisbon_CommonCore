/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:03:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/21 13:41:58 by kwillian         ###   ########.fr       */
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

//Organization
void	simple_sort_three(t_node **a);
void	init_prepare(t_node **a, t_node **b);

void	rr_prepare(t_node **a, t_node **b, t_node *cheapest_node);
void	rrr_prepare(t_node **a, t_node **b, t_node *cheap);
void	prep_push(t_node **stack, t_node *top, char stack_name);
void	prep_push_combined(t_node **a, t_node **b, t_node *cheap);
void	simple_sort(t_node **a, t_node **b);
//node creation
t_node	*ft_lstnew2(int number, int idx);
void	ft_lstadd_front2(t_node **lst, t_node *new);
//moves
void	sa(t_node *original, char c);
void	sb(t_node *original, char c);
void	ss(t_node *a, t_node *b, char c);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a, char c);
void	rb(t_node **b, char c);
void	rra(t_node **a, char c);
void	rr(t_node **a, t_node **b, char c);
void	rrb(t_node **b, char c);
void	rrr(t_node **a, t_node **b, char c);
//free
void	free_list(t_node *head);
void	free_list(t_node *head); // repetido
void	free_split_args(char **args);
//insert
void	insert(t_node **a, long int data, int idx);
void	process_args(int argc, char *argv[], t_node **a, t_node **b);
void	push_3_on_a(t_node **a, t_node **b);
t_node	*get_cheapest(t_node *stack);
//helpers
int		stack_len(t_node *stack);
void	create_index(t_node *stack);
long	ft_atol(const char *str);
t_node	*find_max(t_node *stack);
t_node	*find_min(t_node *stack);
//sorters
bool	is_sorted(t_node *lst);
bool	is_sorted_b(t_node *lst);
int		is_sorted_desc(t_node *stack);
void	min_on_top(t_node **stack);
//Setters
void	set_target_a(t_node *a, t_node *b);
void	cost_checker(t_node *a, t_node *b);
void	cheaper_one(t_node *lst);
void	move_cheapest(t_node **a, t_node **b);
void	sort_stack_b(t_node **b);
void	indexes(t_node **a, t_node **b);
void	move_b_to_a(t_node **a, t_node **b);
t_node	*find_best_target(t_node *a, t_node *b);
//printers
void	printa(t_node *a);
void	printb(t_node *b);
//errors
bool	check_errors(int argc, char *argv[]);
bool	signals2(char **c, int i, int j);
bool	is_duplicate(char **args, int number, int size);
bool	check_tokens(char **tokens);
#endif