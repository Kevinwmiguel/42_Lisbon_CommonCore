/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 00:01:00 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/18 00:38:36 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <ctype.h>

size_t	ft_strlenn(char *s)
{
	int	i;

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
	int		k;
	int		j;

	k = 0;
	j = 0;
	str = (char *)malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[k] != '\0')
		str[j++] = s1[k++];
	free(s1);
	k = 0;
	while (s2 != NULL && s2[k] != '\0')
	{
		str[j++] = s2[k++];
		if (s2[k - 1] == '\n')
			break ;
	}
	str[j] = '\0';
	return (str);
}
