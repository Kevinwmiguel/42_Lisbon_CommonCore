/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:01:00 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/14 23:03:24 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <ctype.h>

size_t	ft_strlen1(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlen1(s1) + ft_strlen1(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i] != '\0')
		str[j++] = s1[i++];
	free(s1);
	i = 0;
	int only_spaces = 1;
	while (s2 != NULL && s2[i] != '\0')
	{
		if (!isspace(s2[i]) && s2[i] != '\n')
			only_spaces = 0;
		str[j++] = s2[i++];
		if (s2[i - 1] == '\n')
			break ;
	}
	if (only_spaces)
		return (NULL);
	str[j] = '\0';
	return (str);
}
