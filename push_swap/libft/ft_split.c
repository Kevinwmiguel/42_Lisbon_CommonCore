/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:59:58 by kwillian          #+#    #+#             */
/*   Updated: 2024/07/01 00:32:26 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_memfree(char **buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

static char	**ft_split_words(char **buffer, const char *s, char c)
{
	char	**word;
	size_t	length;
	size_t	i;

	i = 0;
	length = 0;
	word = buffer;
	while (s[i])
	{
		if (s[i] != c)
		{
			length++;
			if (s[i + 1] == '\0' || s[i + 1] == c)
			{
				*word = ft_substr(s, i - length + 1, length);
				if (!(*word))
					return (ft_memfree(buffer), NULL);
				word++;
				length = 0;
			}
		}
		i++;
	}
	*word = NULL;
	return (buffer);
}

static int	ft_countsubstrings(const char *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	if (s[i] != c && s[i] != '\0')
		counter++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				counter++;
			if (s[i] == '\0')
				return (counter);
		}
		i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	int		size;

	if (!s)
		return (NULL);
	size = ft_countsubstrings(s, c);
	buffer = malloc((size + 1) * sizeof(char *));
	if (!buffer)
		return (NULL);
	buffer = ft_split_words(buffer, s, c);
	return (buffer);
}