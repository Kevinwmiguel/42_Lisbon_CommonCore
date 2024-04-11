/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:41 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:01:42 by kwillian         ###   ########.fr       */
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

char *ft_strjoin(char const *s1, char const *s2)
{
    unsigned int    i;
    unsigned int    j;
    int size;

    i = 0;
    size = ft_strlen(s1) + ft_strlen(s2);
    char *nova = (char *)malloc(size + 1);
    if (!nova)
        return NULL;
    while(s1[i] != '\0')
    {
        nova[i] = s1[i];
        i++;
    }
    j = 0;
    while(s2[j] != '\0')
    {
        nova[i] = s2[j];
        j++;
        i++;
    }
    nova[i] = '\0';
    return nova;
}