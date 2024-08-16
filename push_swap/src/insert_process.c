/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:12:02 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/16 02:41:33 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
		ft_printf("=================================\n");
		ft_printf("A posiçao %d: %d\n", current->index, current->number);
		ft_printf("Atual target = %d\n", current->target->number);
		ft_printf("CUsto para enviar : %d\n", current->cost_to_push);
		ft_printf("cheapest? %s\n", current->cheapest ? "true" : "false");
		current = current->next;
	};
}
// void	printb(t_node *b)
// {
// 	t_node		*current;

// 	current = b;
// 	while (current != NULL)
// 	{
// 		if (current->target == NULL)
// 			break;
// 		printf("=================================\n");
// 		ft_printf("           B posiçao %d: %d ", current->index, current->number);
// 		// printf("Custo %d | Upmedium? %s\n", current->cost_to_push, current->upmedium ? "true" : "false");
// 		// printf("cheapest? %s\n", current->cheapest ? "true" : "false");
		
// 		current = current->next;
// 	};
// }

void	process2args(int argc, char *argv[], t_node **a)
{
	int	i;

	i = argc - 1; // Começa do final para o início
	while (i > 0) // Muda a condição para inserir até argv[1]
	{
		insert(a, ft_atoi(argv[i]), argc - i - 1);
		i--;
	}
}


void	process_args(int argc, char *argv[], t_node **a, t_node **b)
{
	char	**tokens;
	int		i;
	int		token_count;

	i = 0;
	if (argc > 2)
	{
		process2args(argc, argv, a);
	}
	else if (argc == 2)
	{
		tokens = ft_split(argv[1], ' ');
		if (tokens == NULL)
			return ;
		// Conta o número de tokens para saber o índice inicial
		token_count = 0;
		while (tokens[token_count] != NULL)
			token_count++;
		// Insere os elementos de trás para frente
		while (--token_count >= 0)
		{
			insert(a, ft_atoi(tokens[token_count]), i);
			i++;
		}
		free_split_args(tokens);
	}
	create_index(*a);
	//printa(*a);
	if (stack_len(*a) > 2)
		push_3_on_a(a, b);
	else if (stack_len(*a) == 2)
	{
		if ((*a)->number > (*a)->next->number)
			sa(*a, 'a');
	}
	create_index(*a);
}

