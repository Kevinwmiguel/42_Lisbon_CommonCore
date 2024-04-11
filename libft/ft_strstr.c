/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:02:16 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

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