/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:23 by kwillian          #+#    #+#             */
/*   Updated: 2024/08/14 18:02:00 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ispace(char c)
{
	return (c == ' ' || c == '\r' || c == '\f' || \
			c == '\t' || c == '\v' || c == '\n');
}

int	ft_atoi(const char *str)
{
	int	i;
	int	ngt;
	int	nmr;

	nmr = 0;
	ngt = 1;
	i = 0;
	while (ft_ispace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ngt = -ngt;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nmr = nmr * 10 + (str[i] - '0');
		i++;
	}
	return (nmr * ngt);
}

long	ft_atol(const char *str)
{
	long	i;
	long	ngt;
	long	nmr;

	nmr = 0;
	ngt = 1;
	i = 0;
	while (ft_ispace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			ngt = -ngt;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nmr = nmr * 10 + (str[i] - '0');
		i++;
	}
	return (nmr * ngt);
}
