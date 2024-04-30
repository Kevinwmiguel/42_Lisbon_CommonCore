/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 23:34:46 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/30 16:27:46 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "ft_printf.h"

static size_t	contnum(int n)
{
	long	number;
	int		temp;

	number = n;
	temp = 0;
	if (number <= 0)
	{
		temp++;
		number = -number;
	}
	while (number > 0)
	{
		number /= 10;
		temp++;
	}
	return (temp);
}

char	*ft_itoa(int n)
{
	char	*buffer;
	int		size;
	long	temp;

	size = contnum(n);
	buffer = ft_calloc(size + 1, 1);
	if (!buffer)
		return (NULL);
	temp = n;
	buffer[0] = '0';
	if (n < 0)
	{
		buffer[0] = '-';
		temp = (-temp);
	}
	size--;
	while (temp > 0)
	{
		buffer[size] = (temp % 10) + '0';
		temp /= 10;
		size--;
	}
	return (buffer);
}

// int main()
// {
//     int test =  14569;
//     char *numero; 
//     numero = ft_itoa(test);
//     printf("%s", numero);
//     free(numero); // Liberando a memória alocada
//     return (0);
// }
