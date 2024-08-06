/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:27:43 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/04 20:27:43 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

typedef struct s_node
{
	int					number;
	int					index;
	int					cost_to_push;
	int					upmedian;
	int					cheapest;
	struct s_node	*target;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void			current_index(t_node *stack);
void			set_cheapest(t_node *stack);
void			run_nodes_a(t_node *a, t_node *b);
void			run_nodes_b(t_node *a, t_node *b);
void			push_prep(t_node **s, t_node *n, char c);
t_node	*get_cheapest(t_node *stack);
void			init_stack_a(t_node **a, char **argv);
char			**ftsplit(char *s, char c);
int				stack_len(t_node *stack);
t_node	*find_last(t_node *stack);
bool			stack_sorted(t_node *stack);
t_node	*find_min(t_node *stack);
t_node	*find_max(t_node *stack);
void			simple_sort(t_node **a);
void			sort_all_numbers(t_node **a, t_node **b);
void			swap(t_node **head);
void			move_b_to_a(t_node **a, t_node **b);
void			sa(t_node **a, bool print);
void			sb(t_node **b, bool print);
void			ss(t_node **a, t_node **b, bool print);
void			ra(t_node **a, bool print);
void			rb(t_node **b, bool print);
void			rr(t_node **a, t_node **b, bool print);
void			rra(t_node **a, bool print);
void			rrb(t_node **b, bool print);
void			rrr(t_node **a, t_node **b, bool print);
void			pa(t_node **a, t_node **b, bool print);
void			pb(t_node **b, t_node **a, bool print);
int				error_syntax(char *str_n); 
int				duplicated(t_node *a, int n);
void			free_stack(t_node **stack);
void			free_errors(t_node **a);
void			free_nodes(char  **argv);

#endif