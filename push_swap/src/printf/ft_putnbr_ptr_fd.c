/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 06:49:31 by kwillian          #+#    #+#             */
/*   Updated: 2024/06/10 18:22:19 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	putthepointer(unsigned long long nbr)
{
	char	*ptr_digits;
	int		count;

	count = 0;
	ptr_digits = "0123456789abcdef";
	if (nbr >= 16)
	{
		count += putthepointer(nbr / 16);
		count += putthepointer(nbr % 16);
	}
	else
	{
		count += ft_putchar_fd2(ptr_digits[nbr], 1);
	}
	return (count);
}

int	ft_putnbr_ptr_fd(unsigned long long nbr)
{
	int	count;

	count = 2;
	if (!nbr)
	{
		write(1, "(nil)", 5);
		count = 5;
		return (5);
	}
	ft_putstr_fd2("0x", 1);
	count += putthepointer(nbr);
	return (count);
}
