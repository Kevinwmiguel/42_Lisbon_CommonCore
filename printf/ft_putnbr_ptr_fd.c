/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 06:49:31 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/30 18:11:21 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	putThePointer(unsigned long long nbr)
{
	char	*ptr_digits;
	int	count;

	count = 0;
	ptr_digits = "0123456789abcdef";
	if (nbr >= 16)
	{
		count += putThePointer(nbr / 16);
		count += putThePointer(nbr % 16);
	}
	else
	{
		count += ft_putchar_fd(ptr_digits[nbr], 1);
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
	ft_putstr_fd("0x", 1);
	count += putThePointer(nbr);
	//printf("Contagem total de pointer %d ", count);
	return (count);
}
