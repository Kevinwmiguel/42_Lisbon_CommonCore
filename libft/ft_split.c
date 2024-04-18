/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:59:58 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 08:11:16 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static int	count_substrings(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*copy_substring(const char *s, char c)
{
	const char	*start;
	int			len;
	char		*sub;

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

static void	free_result(char **result, int count)
{
	while (count--)
		free(result[count]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;
	int		i;

	if (!s || !c)
		return (NULL);
	count = count_substrings(s, c);
	result = malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s && i < count)
	{
		result[i] = copy_substring(s, c);
		if (!result[i])
		{
			free_result(result, i);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	result[i] = NULL;
	return (result);
}
