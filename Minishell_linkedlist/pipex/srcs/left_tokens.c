/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:20:43 by kwillian          #+#    #+#             */
/*   Updated: 2025/05/06 21:15:48 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

// void	remove_all_double_left_tokens(t_pipesort *piped)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (piped->content[i])
// 	{
// 		if (ft_strncmp(piped->content[i], "<<", 3) == 0)
// 		{
// 			j = i;
// 			while (piped->content[j + 2])
// 			{
// 				piped->content[j] = piped->content[j + 2];
// 				j++;
// 			}
// 			piped->content[j] = NULL;
// 			piped->content[j + 1] = NULL;
// 			// após a remoção, não incrementa i (porque o conteúdo foi "empurrado")
// 			continue;
// 		}
// 		i++;
// 	}
// }

int	find_input_file_index(char **content, int i)
{
	while (content[i])
	{
		if (ft_strncmp(content[i], "<", 1) == 0)
		{
			if (content[i + 1])
				return (i + 1);
			else
				return (-1); // erro não tem arquivo depois do <
		}
		i++;
	}
	return (-1);
}

void	remove_double_left_tokens(t_pipesort *piped, int limiter_idx)
{
	int	i;

	i = limiter_idx - 1;
	while (piped->content[i + 2])
	{
		piped->content[i] = piped->content[i + 2];
		i++;
	}
	piped->content[i] = NULL;
	piped->content[i + 1] = NULL;
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

int	find_double_left_index(t_pipesort *piped)
{
	int			i;
	t_pipesort	*temp;

	temp = piped;
	if (!temp->content)
		return (-1);
	i = 0;
	while (temp->content[i])
	{
		i++;
		if (ft_strncmp(temp->content[i], "<<", 2) == 0 && \
			ft_strlen(temp->content[i]) == 2)
			return (i);
	}
	return (-1);
}


void	handle_redirection_input(t_pipesort *piped)
{
	int		i;
	int		idx_limiter;
	int		file_index;

	if (!piped || !piped->content || !piped->redirection_type)
		return ;
	i = 0;
	while (piped->content[i])
	{
		if (ft_strncmp(piped->redirection_type, "double left", 11) == 0)
		{
			idx_limiter = find_double_left_index(piped) + 1;
			if (!piped->content[idx_limiter])
			{
				write(2, "Limite ausente para heredoc\n", 29);
				exit(1);
			}
			piped->heredoc_fd = here_doc(piped->content[idx_limiter]);
			remove_double_left_tokens(piped, idx_limiter);
			break ;
		}
		else if (ft_strncmp(piped->redirection_type, "one left", 8) == 0)
		{
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
			break ;
		}
		i++;
	}
}
