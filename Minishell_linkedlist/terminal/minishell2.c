/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 01:00:10 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/03 01:49:30 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	input_fixer(char *input)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (input[i] && input[i] == 32)
		i++;
	while (input[i] && input[i] != 32)
		i++;
	while (input[i] && input[i] == 32)
		i++;
	while (input[i])
	{
		input[j] = input[i];
		i++;
		j++;
	}
	input[j] = '\0';
}

int	where_is_echoj(char ***bizarre)
{
	int	x;
	int	j;

	x = -1;
	j = -1;
	while (bizarre[++x])
	{
		j = -1;
		while (bizarre[x][++j])
		{
			if (ft_strncmp("echo", bizarre[x][j], 4) == 0)
				return (j);
		}
	}
	return (-1);
}

int	where_is_echox(char **bizarre)
{
	int	x;

	x = -1;
	while (bizarre[++x])
	{
		if (ft_strncmp("echo", bizarre[x], 4) == 0)
			return (x);
	}
	return (-1);
}

char	*double_to_one(char **dptr)
{
	int		j;
	char	*rtn;
	char	*copy;

	j = -1;
	rtn = NULL;
	while (dptr[++j])
	{
		if (rtn)
			copy = ft_strdup(rtn);
		else
			copy = ft_strdup("");
		if (rtn)
			free (rtn);
		rtn = ft_strjoinn(copy, dptr[j]);
		free (copy);
	}
	return (rtn);
}

size_t	len_dp(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
