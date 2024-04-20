/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:59:58 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/20 03:54:30 by kwillian         ###   ########.fr       */
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

static void	free_split(char **buffer, int c)
{
	while (c >= 0)
		free(buffer[c--]);
	free(buffer);
}

static char	**shorterline(char **buffer,const char *s, char c)
{
	int		size;
	int		start;
	int		length;

	size = 0;
	start = 0;
	length = 0;
	while (s[start])
	{
		while (s[start] == c)
			start++;
		length = 0;
		while (s[start + length] != c && s[start + length])
			length++;
		if (length > 0)
			buffer[size] = ft_substr(s, start, length);
		if (!buffer[size++])
		{
			free_split(buffer, (size) - 1);
			return (NULL);
		}
		start += length;
	}
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;

	if (!s)
		return (NULL);
	buffer = ft_calloc(count_substrings(s, c) + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	buffer = shorterline(buffer, s, c);
	return (buffer);
}

#include <stdio.h>

int	main()
{
	const char	*palavra = "ola senhoras, e senhores, e bichos";
	char **new = ft_split(palavra, ',');
	int	i = 0;	
	printf("antiga:  %s \n", palavra);
	if (new)
	{
		while(new[i])
		{
			printf("nova: %s \n ", new[i]);
			i++;
		}
	}
	return 0;
}
