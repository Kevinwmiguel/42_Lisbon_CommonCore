/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:53:10 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/29 21:04:17 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_puthex(unsigned int n, char format)
{
	char	*hex_digits;

	if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	else if (format == 'x')
		hex_digits = "0123456789abcdef";
	if (n >= 16)
	{
		ft_puthex(n / 16, format);
		ft_putchar_fd((hex_digits[n % 16]), 1);
	}
	else
		ft_putchar_fd((hex_digits[n]), 1);
}