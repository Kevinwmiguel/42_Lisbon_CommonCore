/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/19 19:44:01 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *ocurrence)
{
	int	i;
	int	size;
	int	find;

	if (!src)
		return (NULL);
	size = ft_strlen(ocurrence);
	while (*src != '\0')
	{
		i = 0;
		find = 0;
		while (src[i] == ocurrence[i] && ocurrence[i] != '\0')
		{
			i++;
			find++;
		}
		if (find == size)
			return ((char *)src);
		src++;
	}
	return (NULL);
}
