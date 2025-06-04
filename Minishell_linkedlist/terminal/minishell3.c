/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:43:31 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/03 01:55:40 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

bool	redirection_verifier_utils(t_pipesort *piped, int i, int j)
{
	piped->redirection_type = NULL;
	if (ft_strncmp(piped->content[j] + i, "<", 1) == 0 && \
		piped->content[j][i + 1] != '<')
	{
		piped->redirection_type = "one left";
		return (true);
	}
	else if (ft_strncmp(piped->content[j] + i, "<<", 2) == 0)
	{
		piped->redirection_type = "double left";
		return (true);
	}
	else if (ft_strncmp(piped->content[j] + i, ">", 1) == 0 && \
		piped->content[j][i + 1] != '>')
	{
		piped->redirection_type = "one right";
		return (true);
	}
	else if (ft_strncmp(piped->content[j] + i, ">>", 2) == 0)
	{
		piped->redirection_type = "double right";
		return (true);
	}
	return (false);
}

bool	redirection_verifier(t_pipesort *piped)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (piped->content[++j])
	{
		while (piped->content[j][++i])
		{
			if (redirection_verifier_utils(piped, i, j) == true)
			{
				return (true);
			}
		}
		i = -1;
	}
	return (false);
}

int	correct_redirection(char **dptr)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (dptr[++j])
	{
		while (dptr[j][++i])
		{
			if (i != 0 && dptr[j][i] == '<' && \
				dptr[j][i - 1] == '<' && dptr[j][i + 1] == '<')
				return (0);
			if (i != 0 && dptr[j][i] == '>' \
				&& dptr[j][i - 1] == '>' && dptr[j][i + 1] == '>')
				return (0);
			else if (dptr[j][i] == '<' && (dptr[j][i + 1] == '>' || \
				dptr[j][i + 1] == '|' || dptr[j][i + 1] == '&'))
				return (0);
			else if (dptr[j][i] == '>' && (dptr[j][i + 1] == '<' || \
				dptr[j][i + 1] == '|' || dptr[j][i + 1] == '&'))
				return (0);
		}
		i = -1;
	}
	return (1);
}
