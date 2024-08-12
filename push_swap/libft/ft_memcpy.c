/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:07 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 13:42:23 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*new;
	size_t			i;

	if (!dst && !src)
		return (NULL);
	new = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*(char *)(new + i) = *(char *)(src + i);
		i++;
	}
	return (new);
}
// #include <stdio.h>
// int main()
// {
//     char j[16]; // Alocar memória suficiente para armazenar os caracteres
//     const char *i = "123456789101213"; // Declarar i como const char
//     size_t x = 15;
//     ft_memcpy(j, i, x);
//     printf("%s\n", j);

//     return (0);
// }
