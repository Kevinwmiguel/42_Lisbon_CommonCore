/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:27 by kwillian          #+#    #+#             */
/*   Updated: 2025/05/04 21:03:47 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libs/builtins.h"

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
		if (*arg == ' ' || *arg == '<' || *arg == '>' || \
			*arg == '|' || *arg == 'l')
			return (1);
		arg++;
	}
	return (0);
}
