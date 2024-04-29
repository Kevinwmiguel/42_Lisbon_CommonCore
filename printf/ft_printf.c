/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:08:03 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/29 21:04:25 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

static void	ft_putnbr(unsigned int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar_fd((n % 10 + '0'), 1);
	}
	else
		ft_putchar_fd((n + '0'), 1);
}

static void	ft_putnbr_ptr_fd(unsigned long long nbr)
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

static int	process_format(const char **format, va_list args)
{
	*format += 1;
	if (**format == 'u')
		ft_putnbr(va_arg(args, unsigned int));
	else if (**format == 'd' || **format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (**format == 'x' || **format == 'X')
		ft_puthex(va_arg(args, unsigned int), **format);
	else if (**format == 'c')
		ft_putchar_fd(((char)va_arg(args, int)), 1);
	else if (**format == 's')
		ft_putstr_fd((va_arg(args, char *)), 1);
	else if (**format == 'p')
	{
		ft_putstr_fd(("0x"), 1);
		ft_putnbr_ptr_fd(va_arg(args, unsigned long long));
	}
	else if (**format == '%')
		ft_putchar_fd(('%'), 1);
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
			ft_putchar_fd((*format), 1);
			format++;
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_printf_internal(format, args);
	va_end(args);
	return (count);
}
int main()
{
    char i = 'C';
    char *str = "palavra";
    unsigned int x = -958;
    int j = -2147483648;

    ft_printf("FUNCAO FT_PRINTF\n");
    ft_printf("This is a letter %c \n", i);
    ft_printf("This is a string %s \n", str);
    ft_printf("This is a pointer %p tentativa \n", &x);
    ft_printf("This is a int nmb with D %d \n", x);
    ft_printf("This is a int nmb with I %i \n", j);
    ft_printf("This is a int hex decimal LOWER %x  \n", x);
    ft_printf("This is a int hex decimal UPPER %X  \n", x);
    ft_printf("This is a uns dec nbm %u  \n", x);
    ft_printf("This is a porcent %%  \n");

    printf("\nFUNCAO PRINT\n");
    printf("This is a letter %c \n", i);
    printf("This is a string %s \n", str);
    printf("This is a pointer %p tentativa \n", &x);
    printf("This is a int nmb %d \n", x);
    printf("This is a int nmb %i \n", j);
    printf("This is a int hex decimal LOWER %x\n", x);
    printf("This is a int hex decimal UPPER %X\n", x);
    printf("This is a uns dec nbm %u \n", x);
    printf("This is a porcent %% ssss \n");
    return 0;
}
