/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:01:54 by kwillian          #+#    #+#             */
/*   Updated: 2025/05/03 22:49:53 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

int here_doc(char *limiter)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		perror("Erro ao criar o pipe");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;

		if (ft_strlen(line) == ft_strlen(limiter) + 1 && \
			ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && \
			line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}

		write(fd[1], line, ft_strlen(line));
		free(line);
	}

	close(fd[1]);
	return (fd[0]);
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

void	remove_double_left_tokens(t_pipesort *piped, int limiter_idx)
{
	int	i;

	// Começamos no índice do '<<', que está uma posição antes do limiter
	i = limiter_idx - 1;
	while (piped->content[i + 2])
	{
		piped->content[i] = piped->content[i + 2];
		i++;
	}
	piped->content[i] = NULL;
	piped->content[i + 1] = NULL;
}

void	handle_redirection_input(t_pipesort *piped)
{
	int		fd;
	int		i;
	int		j;
	int		idx_limiter = 0;

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
			j = i;
			remove_double_left_tokens(piped, idx_limiter);
			break ;
		}
		else if (ft_strncmp(piped->redirection_type, "one left", 8) == 0)
		{
			if (!piped->content[i + 2])
			{
				write(2, "Arquivo não fornecido para redirecionamento\n", 45);
				exit(1);
			}
			fd = open(piped->content[i + 2], O_RDONLY);
			if (fd < 0)
			{
				perror("open");
				exit(1);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
			j = i;
			while (piped->content[j + 3])
			{
				piped->content[j] = piped->content[j + 3];
				j++;
			}
			piped->content[j] = NULL;
			break ;
		}
		i++;
	}
}
