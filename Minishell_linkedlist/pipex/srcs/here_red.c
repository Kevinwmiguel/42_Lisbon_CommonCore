/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_red.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:01:54 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/03 00:40:38 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

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

void	open_last_output_file(t_pipesort *piped, \
	int last_index, char *redir_type)
{
	if (ft_strncmp(redir_type, ">>", 2) == 0)
	{
		piped->outfd = open(piped->content[last_index + 1], \
			O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		piped->outfd = open(piped->content[last_index + 1], \
			O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (piped->outfd < 0)
	{
		perror("open");
		exit(1);
	}
}

void	find_last_output_redir(t_pipesort *piped, \
	int *last_index, char **redir_type)
{
	int	i;

	i = 0;
	*last_index = -1;
	*redir_type = NULL;
	while (piped->content[i])
	{
		if ((ft_strncmp(piped->content[i], ">", 2) == 0 || \
			ft_strncmp(piped->content[i], ">>", 3) == 0) && \
			piped->content[i + 1])
		{
			*last_index = i;
			*redir_type = piped->content[i];
		}
		i++;
	}
}

void	handle_redirection_right_input(t_pipesort *piped)
{
	int		last_index;
	char	*redir_type;

	if (!piped || !piped->content)
		return ;
	find_last_output_redir(piped, &last_index, &redir_type);
	if (last_index == -1)
		return ;
	open_last_output_file(piped, last_index, redir_type);
	remove_all_output_redirs(piped, last_index);
}

int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}
