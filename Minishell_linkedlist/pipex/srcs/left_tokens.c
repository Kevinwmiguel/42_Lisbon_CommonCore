/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:20:43 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/01 18:30:33 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

void	remove_all_double_left_tokens(t_pipesort *piped)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (piped->content[i])
	{
		if (ft_strncmp(piped->content[i], "<<", 3) == 0)
		{
			j = i;
			while (piped->content[j + 2])
			{
				piped->content[j] = piped->content[j + 2];
				j++;
			}
			piped->content[j] = NULL;
			piped->content[j + 1] = NULL;
			continue ;
		}
		i++;
		k++;
	}
}

void	remove_one_left_tokens(t_pipesort *piped, int file_idx)
{
	int	i;

	i = file_idx - 1;
	while (piped->content[i + 1])
	{
		piped->content[i] = piped->content[i + 1];
		i++;
	}
	piped->content[i] = NULL;
}

void	handle_double_left(t_pipesort *piped)
{
	int	idx;
	int	idx_limiter;

	idx = 0;
	while ((find_next_double_left_index(piped, idx)) != -1)
	{
		idx = find_next_double_left_index(piped, idx);
		idx_limiter = idx + 1;
		if (!piped->content[idx_limiter])
		{
			write(2, "Limite ausente para heredoc\n", 29);
			exit(1);
		}
		piped->heredoc_fd = here_doc(piped->content[idx_limiter]);
		idx = idx_limiter;
	}
	remove_all_double_left_tokens(piped);
}

void	handle_single_left(t_pipesort *piped)
{
	int	file_index;

	file_index = find_input_file_index(piped->content, 0);
	if (file_index == -1)
	{
		write(2, "Arquivo não fornecido para redirecionamento\n", 45);
		exit(1);
	}
	piped->infd = open(piped->content[file_index], O_RDONLY);
	if (piped->infd < 0)
	{
		perror("open");
		exit(1);
	}
	remove_one_left_tokens(piped, file_index);
}

void	handle_redirection_left_input(t_pipesort *piped)
{
	int	i;

	i = 0;
	if (!piped || !piped->content || !piped->redirection_type)
		return ;
	while (piped->content[i])
	{
		if (ft_strncmp(piped->content[i], "<<", 3) == 0)
		{
			handle_double_left(piped);
			i = 0;
			continue ;
		}
		else if (ft_strncmp(piped->content[i], "<", 2) == 0)
		{
			handle_single_left(piped);
			i = 0;
			continue ;
		}
		i++;
	}
}
