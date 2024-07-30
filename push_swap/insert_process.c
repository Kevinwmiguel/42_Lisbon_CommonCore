/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:12:02 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/30 04:38:57 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert(t_node **a, long int data, int idx)
{
	t_node		*new_node;

	new_node = ft_lstnew2(data, idx);
	if (new_node == NULL)
	{
		ft_printf("Erro de criação de novo nó\n");
		return ;
	}
	ft_lstadd_front2(a, new_node);
}

void	printa(t_node *a)
{
	t_node		*current;

	current = a;
	while (current != NULL)
	{

		ft_printf("A posiçao %d: %d\n", current->index, current->number);
		current = current->next;
	};
}
void	printb(t_node *b)
{
	t_node		*current;

	current = b;
	while (current != NULL)
	{
		printf("=================================\n");
		ft_printf("           B posiçao %d: %d atual target = %d\n", current->index, current->number, current->target->number);
		printf("Custo %d | Upmedium? %s\n", current->cost_to_push, current->upmedium ? "true" : "false");
		printf("cheapest? %s\n", current->cheapest ? "true" : "false");
		
		current = current->next;
	};
}

void	process2args(int argc, char *argv[], t_node **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		insert(a, ft_atoi(argv[i]), i - 1);
		i++;
	}
}

void	process_args(int argc, char *argv[], t_node **a, t_node **b)
{
	char	**tokens;
	int		i;

	i = 0;
	if (argc > 2)
		process2args(argc, argv, a);
	else if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (tokens == NULL)
			return ;
		while (tokens[i] != NULL)
		{
			insert(a, ft_atoi(tokens[i]), i);
			i++;
		}
		free_split_args(tokens);
	}
	if (stack_len(*a) > 2)
		push_3_on_a(a, b);
	else
		if ((*a)->number > (*a)->next->number)
			sa(*a, 'a');
}
