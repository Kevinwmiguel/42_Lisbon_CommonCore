/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:01:54 by kwillian          #+#    #+#             */
/*   Updated: 2025/05/03 00:18:17 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

int	here_doc(char *limiter)
{
	char	*line;
	int		fd[2];

	line = NULL;
	if (pipe(fd) == -1)
	{
		perror("Erro ao criar o pipe");
		exit(1);
	}
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			perror("Erro ao ler a linha");
			exit(1);
		}
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0 && \
			ft_strlen(line) == ft_strlen(limiter))
			break ;
		write(fd[1], line, ft_strlen(line)); // Conversar com o thiago sobre isso
		free(line);
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}

void	handle_redirection_input(t_pipesort *piped)
{
	int	fd;
	int	i;
	int	found_heredoc;

	if (!piped || !piped->content)
		return ;

	i = 0;
	fd = -1;
	found_heredoc = 0;
	while (piped->content[i])
	{
		if (ft_strncmp(piped->redirection_type, "double left", 11) == 0)
		{
			found_heredoc = 1;
			fd = here_doc(piped->content[i + 1]);
			dup2(fd, STDIN_FILENO);
			close(fd);
			while (piped->content[i])
			{
				piped->content[i] = piped->content[i + 2];
				i++;
			}
			i = 0;
		}
		else
			i++;
	}
	if (!found_heredoc)
	{
		i = 0;
		while (piped->content[i])
		{
			if (ft_strncmp(piped->redirection_type, "one left", 8) == 0)
			{
				if (access(piped->content[i + 1], F_OK) == -1)
				{
					perror("Arquivo inexistente");
					exit(1);
				}
				fd = open(piped->content[i + 1], O_RDONLY);
				if (fd < 0)
				{
					perror("open");
					exit(1);
				}
				dup2(fd, STDIN_FILENO);
				close(fd);
				while (piped->content[i])
				{
					piped->content[i] = piped->content[i + 2];
					i++;
				}
				break ;
			}
			i++;
		}
	}
}
