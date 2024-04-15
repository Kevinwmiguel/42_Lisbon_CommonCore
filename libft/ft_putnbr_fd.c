/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:22:22 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/15 19:25:59 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*number;
	size_t	size;

	number = ft_itoa(n);
	size = ft_strlen(number);
	write(fd, number, size);
}
// int main()
// {
// 	ft_putnbr_fd(4589563, 1);
// 	return (0);
// }
