/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:36 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:01:37 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i]!= '\0')
        i++;
    return i;
}

char *strdup(const char *str)
{
    size_t i;
    size_t len;

    len = ft_strlen(str);
    i = 0;
    char *string = (char *)malloc(len + 1);
    if(!string)
        return NULL;
    while(i < len)
    {
        string[i] = str[i];
        i++;
    }
    string[len] = '\0';
    return (char *)string;
}