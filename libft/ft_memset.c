/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:21 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/13 19:06:08 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *ptr, int value, size_t num)
{
    unsigned char *p = ptr;
    size_t  i;

    i = 0;
    while(i < num)
    {
        p[i] = (unsigned char)value;
        i++;
    }
    return ptr;
}