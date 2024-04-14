/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/14 10:13:16 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void			*ft_memmove(void *dst, const void *src, size_t num)
{
    unsigned char *p = (unsigned char *)dst;
    unsigned char *s = (unsigned char *)src;
    int i;

    if (p > s && p < s + num)
    {
        p += num;
        s += num;
        while(num--)
        {
            *p-- = *s--;
        }
    } 
    else 
    {
        i = 0;
		while (i < (int)num)
		{
			*(char*)(dst + i) = *(char*)(src + i);
			i++;
		}
    }
    return (dst);
}
// int main()
// {
//     char j[16]; // Alocar memória suficiente para armazenar os caracteres
//     const char *i = "123456789101213"; // Declarar i como const char *

//     size_t x = 15;
//     ft_memmove(j, i, x);

//     printf("%s\n", j); // Imprimir j para verificar se a função funcionou corretamente

//     return (0);
// }
