/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:03:06 by kwillian          #+#    #+#             */
/*   Updated: 2025/06/04 00:04:52 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s || !fd)
		return ;
	i = ft_strlen(s);
	write(fd, s, i);
}

// int main()
// {
//     ft_putstr_fd("Oi Gente boa!", 1);
//     return (0);
// }
