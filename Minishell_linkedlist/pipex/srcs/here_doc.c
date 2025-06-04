/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:35:53 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/01 18:37:49 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

// int	count_heredocs(t_pipesort *piped)
// {
// 	int count = 0;
// 	int i = 0;

// 	while (piped->content[i])
// 	{
// 		if (ft_strncmp(piped->content[i], "<<", 3) == 0 &&
// 			ft_strlen(piped->content[i]) == 2)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

int	here_doc(char *limiter)
{
	char	*line;
	int		fd[2];

	if (pipe(fd) == -1)
		exit(1);
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
