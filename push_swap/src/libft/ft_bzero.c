/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:40 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 12:03:25 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*(ptr++) = 0;
		n--;
	}
}
// #include <stdio.h>
// int main() {
//     char str[11] = "Hellox";
//     printf("Antes do bzero: %s\n", str);
//     ft_bzero(str, 5);
//     printf("Depois do bzero: %s\n", str);
//     return 0;
// }