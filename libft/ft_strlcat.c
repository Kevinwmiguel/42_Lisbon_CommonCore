/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:45 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:01:58 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
        i++;
    
    return i;
}

size_t  ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t j;
    size_t dst_len;

    dst_len = 0;
    while (dst[dst_len] != '\0' && dst_len < dstsize)
        dst_len++;

    if (dstsize <= dst_len)
        return dst_len + ft_strlen(src);
    i = dst_len;
    j = 0;
    while(src[j] != '\0' && i < dstsize - 1)
    {
        dst[i] = src[j];
        j++;
        i++;
    }
    dst[i] = '\0';
    return dst_len + ft_strlen(src);
}