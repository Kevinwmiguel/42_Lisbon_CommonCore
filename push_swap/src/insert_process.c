/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:12:02 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/21 13:58:47 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	insert(t_node **a, long int data, int idx)
{
	t_node		*new_node;

	new_node = ft_lstnew2(data, idx);
	if (new_node == NULL)
	{
		ft_printf("Error\n");
		return ;
	}
	ft_lstadd_front2(a, new_node);
}

void	process2args(int argc, char *argv[], t_node **a)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		insert(a, ft_atoi(argv[i]), argc - i - 1);
		i--;
	}
}

void	indexes(t_node **a, t_node **b)
{
	create_index(*a);
	create_index(*b);
}

void	magic_happens(t_node **a, t_node **b)
{
	create_index(*a);
	if (stack_len(*a) > 2)
		push_3_on_a(a, b);
	else if (stack_len(*a) == 2)
	{
		if ((*a)->number > (*a)->next->number)
			sa(*a, 'a');
	}
	create_index(*a);
}

void	process_args(int argc, char *argv[], t_node **a, t_node **b)
{
	char	**tokens;
	int		i;
	int		token_count;

	i = 0;
	if (argc > 2)
		process2args(argc, argv, a);
	else if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (tokens == NULL)
			return ;
		token_count = 0;
		while (tokens[token_count] != NULL)
			token_count++;
		while (--token_count >= 0)
		{
			insert(a, ft_atoi(tokens[token_count]), i);
			i++;
		}
		free_split_args(tokens);
	}
	if (!is_sorted(*a))
		magic_happens(a, b);
}
