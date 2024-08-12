/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 13:45:08 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	int				i;
	unsigned char	*p;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	p = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = num - 1;
	if (p > s)
	{
		while (i >= 0)
		{
			p[i] = s[i];
			i--;
		}
	}
	else
		ft_memcpy(p, s, num);
	return (dst);
}
//#include <stdio.h>
// int main()
// {
//     char j[16]; // Alocar memória suficiente para armazenar os caracteres
//     const char *i = "123456789101213"; // Declarar i como const char *
//
//     size_t x = 15;
//     ft_memmove(j, i, x);
//
//     printf("%s\n", j); // Imprimir j para verifi
//     car se a função funcionou corretamente
//
//     return (0);
// }
