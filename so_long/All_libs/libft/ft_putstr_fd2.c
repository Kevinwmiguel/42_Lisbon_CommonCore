/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:03:06 by kwillian          #+#    #+#             */
/*   Updated: 2024/05/03 09:38:55 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putstr_fd2(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (s[0] == '%' && s[i + 1] == '%' && s[i + 2] == '%')
		return (0);
	if (!s || !fd)
		return (0);
	i = ft_strlen(s);
	write(fd, s, i);
	return (i);
}

// int main()
// {
//     ft_putstr_fd2("Oi Gente boa!", 1);
//     return (0);
// }
