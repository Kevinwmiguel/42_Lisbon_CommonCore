/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:41:29 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/15 19:03:43 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	x;

	x = ft_strlen(s);
	write(fd, s, x);
	write(fd, "\n", 1);
}

// int main()
// {
//     ft_putendl_fd("Ola familiaaaax", 1);
//     return (0);
// }
