/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:59:58 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 16:06:34 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_substrings(const char *s, char c)
{
	int	temp;
	int	count;

	temp = 0;
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
		{
			s++;
			temp++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		size;
	int		start;
	int		length;

	size = 0;
	buffer = ft_calloc(count_substrings(s, c) + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	start = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		length = 0;
		while (s[start + length] != c && s[start + length])
			length++;
		if (length > 0)
		{
			buffer[size] = ft_substr(s, start, length);
			size++;
		}
		start += length;
	}
	return (buffer);
}
