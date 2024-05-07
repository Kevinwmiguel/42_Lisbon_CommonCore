/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:01:00 by kwillian          #+#    #+#             */
/*   Updated: 2024/05/07 17:58:07 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    size_t  i;

    i = 0;
    while(s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*nova;
	unsigned int	i;
	unsigned int	j;
	int				size;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	nova = (char *)malloc(size + 1);
	if (!nova)
		return (NULL);
	while (s1[++i] != '\0')
		nova[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
	{
		nova[i] = s2[j];
		j++;
		i++;
	}
	nova[i] = '\0';
	return (nova);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*string;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	string = (char *)malloc(len + 1);
	if (!string)
		return (NULL);
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[len] = '\0';
	return ((char *)string);
}