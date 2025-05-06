/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:01:54 by kwillian          #+#    #+#             */
/*   Updated: 2025/05/06 22:23:42 by kwillian         ###   ########.fr       */
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

void	remove_double_right_tokens(t_pipesort *piped, int limiter_idx)
{
	int	i;

	// Começamos no índice do '>>', que está uma posição antes do limiter
	i = limiter_idx - 1;
	while (piped->content[i + 1])
	{
		piped->content[i] = piped->content[i + 1];
		i++;
	}
	piped->content[i] = NULL;
	piped->content[i - 1] = NULL;
}

void	remove_one_right_tokens(t_pipesort *piped, int file_idx)
{
	int	i;

	i = file_idx - 1; // aponta para o '>'
	printf("index %d\n", file_idx);
	while (piped->content[i + 1])
	{
		piped->content[i] = piped->content[i + 1];
		i++;
	}
	piped->content[i] = NULL;
	piped->content[i - 1] = NULL;
}

int	find_double_right_index(t_pipesort *piped)
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
		if (ft_strncmp(temp->content[i], ">>", 2) == 0 && \
			ft_strlen(temp->content[i]) == 2)
			return (i);
	}
	return (-1);
}

int	find_output_file_index(char **content, int i)
{
	while (content[i])
	{
		if (ft_strncmp(content[i], ">", 2) == 0) // compara string exata
		{
			if (content[i + 1] && content[i + 1][0] != '\0')
				return (i + 1);
			else
				return (-1); // erro: sem arquivo depois de '>'
		}
		i++;
	}
	return (-1); // nenhum '>' encontrado
}

void	handle_redirection_right_input(t_pipesort *piped)
{
	int		i;
	int		idx_file;

	if (!piped || !piped->content || !piped->redirection_type)
		return ;
	i = 0;
	while (piped->content[i])
	{
		if (ft_strncmp(piped->redirection_type, "double right", 12) == 0)
		{
            idx_file = find_double_right_index(piped) + 1;
            piped->outfd = open(piped->content[idx_file], \
                O_WRONLY | O_CREAT | O_APPEND, 0644);
			remove_double_right_tokens(piped, idx_file);
			break ;
		}
		else if (ft_strncmp(piped->redirection_type, "one right", 9) == 0)
		{
			idx_file = find_output_file_index(piped->content, 0);
			piped->outfd = open(piped->content[idx_file], \
                O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (piped->infd < 0)
			{
				perror("open");
				exit(1);
			}
			remove_one_right_tokens(piped, idx_file);
			break ;
		}
		i++;
	}
}
