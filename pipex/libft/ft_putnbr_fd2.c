/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:22:22 by kwillian          #+#    #+#             */
/*   Updated: 2024/09/03 15:52:36 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd2(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd2('-', fd);
		n = (-n);
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_fd2(n / 10, fd);
	ft_putchar_fd2('0' + n % 10, fd);
	count++;
	return (count);
}
// int main()
// {
// 	ft_putnbr_fd2(-3648, 1);
// 	return (0);
// }
