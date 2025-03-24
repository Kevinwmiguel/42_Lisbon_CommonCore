/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:01:54 by kwillian          #+#    #+#             */
/*   Updated: 2025/03/24 22:05:40 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd[1]);
	return (fd[0]);
}

void	handle_redirection_input(char **cmd_args)
{
	int	fd;
	int	i;

	i = 0;
	fd = -1;
	while (cmd_args[i])
	{
		if (ft_strncmp(cmd_args[i], "<<", 2) == 0 && cmd_args[i + 1])
		{
			fd = here_doc(cmd_args[i + 1]);
			dup2(fd, STDIN_FILENO);
			close(fd);
			while (cmd_args[i])
			{
				cmd_args[i] = cmd_args[i + 2];
				i++;
			}
			break ;
		}
		else if (ft_strncmp(cmd_args[i], "<", 1) == 0 && cmd_args[i + 1])
		{
			if (access(cmd_args[i + 1], F_OK) == -1)
			{
				perror("Arquivo inexistente");
				exit(1);
			}
			fd = open(cmd_args[i + 1], O_RDONLY);
			if (fd < 0)
			{
				perror("open");
				exit(1);
			}
			dup2(fd, STDIN_FILENO);
			close(fd);
			while (cmd_args[i])
			{
				cmd_args[i] = cmd_args[i + 2];
				i++;
			}
			break ;
		}
		i++;
	}
}
