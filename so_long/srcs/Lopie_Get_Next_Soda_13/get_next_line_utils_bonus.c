/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 12:03:15 by mmata-al          #+#    #+#             */
/*   Updated: 2024/04/10 13:36:20 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlenn(char *s)
{
	int	melon;

	melon = 0;
	if (!s)
		return (0);
	while (s[melon] != '\0')
	{
		if (s[melon] == '\n')
			return (melon + 1);
		melon++;
	}
	return (melon);
}

char	*ftstrjoin(char *s1, char *s2)
{
	char	*shira;
	int		melon;
	int		soda;

	melon = 0;
	soda = 0;
	shira = (char *)malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!shira)
		return (NULL);
	while (s1 && s1[melon] != '\0')
		shira[soda++] = s1[melon++];
	free(s1);
	melon = 0;
	while (s2 != NULL && s2[melon] != '\0')
	{
		shira[soda++] = s2[melon++];
		if (s2[melon - 1] == '\n')
			break ;
	}
	shira[soda] = '\0';
	return (shira);
}

int	clean_buff(char *buff)
{
	int	i;
	int	j;
	int	nlp;

	i = 0;
	j = 0;
	nlp = 0;
	while (buff[i] != '\0')
	{
		if (nlp)
			buff[j++] = buff[i];
		if (buff[i] == '\n')
			nlp = 1;
		buff[i++] = '\0';
	}
	return (nlp);
}
