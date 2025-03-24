/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:27 by kwillian          #+#    #+#             */
/*   Updated: 2025/03/19 21:17:08 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	checker_envp(char **envp)
{
	if (!envp)
	{
		ft_printf("Error\n No Path\n");
		exit(1);
	}
}

int	check_infile(char *argv)
{
	int	fd_in;

	fd_in = open(argv, O_RDONLY);
	if (fd_in < 0)
	{
		fd_in = open("/dev/null", O_RDONLY);
	}
	return (fd_in);
}

int	is_command(const char *arg)
{
	while (*arg)
	{
		if (*arg == ' ' || *arg == '<' || *arg == '>' || *arg == '|')
			return (1);
		arg++;
	}
	return (0);
}
