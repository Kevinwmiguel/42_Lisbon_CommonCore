/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/13 19:05:00 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strstr(const char *src, const char *ocurrence)
{
    int i;
    int size;
    int find;
    
    size = ft_strlen(ocurrence);
    while (*src != '\0')
    {
        i = 0;
        find = 0;
        while (src[i] == ocurrence[i] && ocurrence[i] != '\0')
        {
            i++;
            find++;
        }
        if (find == size)
        {
            return (char *)src;
        }
        src++;
    }
    return NULL;
}