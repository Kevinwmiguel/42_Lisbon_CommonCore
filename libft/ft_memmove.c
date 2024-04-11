/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:01:16 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memmove(void *destination,const void *source, size_t num)
{
    unsigned char *p = destination;
    unsigned char *s = source;
    
    if (p > s && p < s + num)
    {
        p += num;
        s += num;
        while(num--)
        {
            *p-- = *s--;
        }
    } else {
        while (num--)
        {
            *p++ = *s++;
        }
    }

    
    return destination;
}