/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:10:54 by mmata-al          #+#    #+#             */
/*   Updated: 2024/03/23 11:28:13 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ftstrjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = (char *)malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!str)
		return (NULL);
	while (s1 && s1[i] != '\0')
		str[j++] = s1[i++];
	free(s1);
	i = 0;
	while (s2 != NULL && s2[i] != '\0')
	{
		str[j++] = s2[i++];
		if (s2[i - 1] == '\n')
			break ;
	}
	str[j] = '\0';
	return (str);
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
