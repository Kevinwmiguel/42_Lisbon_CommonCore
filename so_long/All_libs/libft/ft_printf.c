/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:08:03 by kwillian          #+#    #+#             */
/*   Updated: 2024/09/03 15:58:39 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_putnbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar_fd2((n % 10 + '0'), 1);
	}
	else
	{
		ft_putchar_fd2((n + '0'), 1);
		count++;
	}
	return (count);
}

static int	ft_puthex(unsigned int n, char format)
{
	char	*hex_digits;
	int		count;

	count = 0;
	if (format == 'X')
		hex_digits = "0123456789ABCDEF";
	else if (format == 'x')
		hex_digits = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_puthex(n / 16, format);
		count += ft_putchar_fd2((hex_digits[n % 16]), 1);
	}
	else
	{
		ft_putchar_fd2((hex_digits[n]), 1);
		count++;
	}
	return (count);
}

static int	process_format(const char **format, va_list args)
{
	*format += 1;
	if (**format == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	else if (**format == 'd' || **format == 'i')
		return (ft_putnbr_fd2(va_arg(args, int), 1));
	else if (**format == 'x' || **format == 'X')
		return (ft_puthex(va_arg(args, unsigned int), **format));
	else if (**format == 'c')
		return (ft_putchar_fd2(((char)va_arg(args, int)), 1));
	else if (**format == 's')
		return (ft_putstr_fd2((va_arg(args, char *)), 1));
	else if (**format == 'p')
	{
		return (ft_putnbr_ptr_fd(va_arg(args, unsigned long long)));
	}
	else if (**format == '%')
		return (ft_putchar_fd2(('%'), 1));
	return (1);
}

static int	ft_printf_internal(const char *format, va_list args)
{
	int	count;

	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			count += process_format(&format, args);
			format++;
		}
		else
		{
			count += ft_putchar_fd2((*format), 1);
			format++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_printf_internal(format, args);
	va_end(args);
	return (count);
}
