/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:07 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/14 08:37:45 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dst,const void *src, size_t num)
{
    unsigned char *p = dst;
    unsigned char *s = (unsigned char *)src;
    size_t  i = 0;

    while(i < num)
    {
        p[i] = s[i];
        i++;
    }
    return (p);
}