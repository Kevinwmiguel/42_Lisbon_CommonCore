/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:40 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/13 19:06:39 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
    if (s != NULL)
    {
        unsigned char *ptr;
        size_t  i;

        i = 0;
        ptr = (unsigned char *)s;
        while(i < n)
        {
            ptr[i] = 0;
            i++;
        }
    }
}