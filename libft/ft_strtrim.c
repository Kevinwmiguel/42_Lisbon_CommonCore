/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:29 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/13 19:04:51 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*nova;
	int		size;

	i = 0;
	size = ft_strlen(s1);
	nova = (char *)malloc(size + 1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (s1[i] != set[j])
			{
				nova[i] = s1[i];
			}
			j++;
		}
		i++;
	}
	nova[i] != '\0';
	return (nova);
}
