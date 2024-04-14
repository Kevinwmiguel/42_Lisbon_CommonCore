/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 23:34:46 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/14 06:55:45 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <unistd.h>

static int	ft_contnum(int temp)
{
    int count;

    count = 0;
	while(temp != 0)
    {
        temp /= 10;
        count++;
    }
    return count;
}

char    *ft_itoa(int n)
{
    int temp;
    int count = 0;
    int i;

    count = ft_contnum(n);
    size_t size = count;
    char *buffer = (char *)malloc((size + 1) * sizeof(char));
    if(!buffer)
    {
        return NULL;
    }
    i = size -1;
    temp = n;
    while(i >= 0)
    {
        buffer[i] = (temp % 10) + '0';
        temp /= 10;
        i--;
    }
    buffer[size] = '\0';
    return buffer;
}

int main()
{
    int test =  14569;
    char *numero;
    
    numero = ft_itoa(test);
    printf("%s", numero);
    free(numero); // Liberando a memória alocada
    return (0);
}