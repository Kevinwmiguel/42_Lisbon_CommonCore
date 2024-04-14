/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:59:58 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/13 22:48:01 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substrings(const char *s, char c)
{
	int	count;
	
	count = 0;
	while (*s)
	{
		count += (*s == c);
		s++;
	}
	return (count);
}

static char	*copy_substring(const char *s, char c)
{
	const char *start;
	int len;
	char *sub;
	
	while (*s && *s == c)
		s++;
	start = s;
	while (*s && *s != c)
		s++;
	len = s - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, start, len + 1);
	return (sub);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	int count = count_substrings(s, c);
	char **result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	int i = 0;
	while (i < count)
	{
		result[i] = copy_substring(s, c);
		if (!result[i])
		{
			while (i > 0)
				free(result[--i]);
			free(result);
			return (NULL);
		}
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
			s++;
		i++;
	}
	result[count] = NULL;
	return (result);
}
