/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:01:54 by kwillian          #+#    #+#             */
/*   Updated: 2025/05/13 20:35:39 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

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

void	remove_double_right_tokens(t_pipesort *piped, int limiter_idx)
{
	int	i;

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
	int	i = file_idx - 1;

	free(piped->content[i]);
	free(piped->content[i + 1]);

	while (piped->content[i + 2])
	{
		piped->content[i] = piped->content[i + 2];
		i++;
	}
	piped->content[i] = NULL;
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
		if (ft_strncmp(content[i], ">", 2) == 0)
		{
			if (content[i + 1] && content[i + 1][0] != '\0')
				return (i + 1);
			else
				return (-1);
		}
		i++;
	}
	return (-1);
}

void	handle_redirection_right_input(t_pipesort *piped)
{
	int		i = 0;
	int		last_index = -1;
	char	*redir_type = NULL;
	int		j;

	if (!piped || !piped->content)
		return ;

	while (piped->content[i])
	{
		if ((ft_strncmp(piped->content[i], ">", 2) == 0 ||
			ft_strncmp(piped->content[i], ">>", 3) == 0) &&
			piped->content[i + 1])
		{
			last_index = i;
			redir_type = piped->content[i];
		}
		i++;
	}
	if (last_index == -1)
		return ;

	// Abrir o arquivo da última ocorrência
	if (ft_strncmp(redir_type, ">>", 2) == 0)
		piped->outfd = open(piped->content[last_index + 1],
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		piped->outfd = open(piped->content[last_index + 1],
			O_WRONLY | O_CREAT | O_TRUNC, 0644);

	// Agora remover todos os redirecionamentos, exceto o último
	i = 0;
	while (piped->content[i])
	{
		if ((i != last_index) &&
			(ft_strncmp(piped->content[i], ">", 2) == 0 ||
			ft_strncmp(piped->content[i], ">>", 3) == 0) &&
			piped->content[i + 1])
		{
			// Remover redirecionador e seu argumento
			j = i;
			while (piped->content[j + 2])
			{
				piped->content[j] = piped->content[j + 2];
				j++;
			}
			piped->content[j] = NULL;
			piped->content[j + 1] = NULL;
			continue;
		}
		i++;
	}

	// Remover o último redirecionamento também
	j = last_index;
	while (piped->content[j + 2])
	{
		piped->content[j] = piped->content[j + 2];
		j++;
	}
	piped->content[j] = NULL;
	piped->content[j + 1] = NULL;
}



// flag para varios
//FUNCIONAR
//BUILTINS
//FULLPATH
//CAT -E << EOF > OUTPUT.TXT
//CAT -E << EOF > OUTPUT.TXT << EOF > OUTPUT2.TXT
//CAT -E << EOF < EOF > OUTPUT.TXT << EOF > INPUT.TXT