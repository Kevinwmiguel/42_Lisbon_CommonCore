/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:07 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 12:21:25 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	unsigned char		*new_dst;

	if (!dst)
		return (NULL);
	new_dst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		*(char *)(new_dst + i) = *(char *)(src + i);
		i++;
	}
	return (new_dst);
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
