/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ptr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 06:49:31 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/30 06:51:40 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_ptr_fd(unsigned long long nbr)
{
	char	*ptr_digits;

	ptr_digits = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putnbr_ptr_fd(nbr / 16);
		ft_putnbr_ptr_fd(nbr % 16);
	}
	else
		ft_putchar_fd((ptr_digits[nbr]), 1);
}
