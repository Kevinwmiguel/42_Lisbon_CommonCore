/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:07 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:01:08 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    *ft_memcpy(void *destination,const void *source, size_t num)
{
    unsigned char *p = destination;
    unsigned char *s = (unsigned char *)source;
    size_t  i = 0;

    while(i < num)
    {
        p[i] = s[i];
        i++;
    }
    return destination;
}