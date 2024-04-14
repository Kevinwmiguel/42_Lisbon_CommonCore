/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/14 08:35:07 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t num)
{
    unsigned char *p = dst;
    const unsigned char *s = src;
    
    if (p > s && p < s + num)
    {
        p += num;
        s += num;
        while(num--)
        {
            *p-- = *s--;
        }
    } else {
        ft_memcpy(p, s, num);
    }
    return (p);
}