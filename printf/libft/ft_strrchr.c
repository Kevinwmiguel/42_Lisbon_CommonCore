/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:11 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/19 19:44:14 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	int		i;
	char	*dst;

	if (!str)
		return (NULL);
	dst = (char *)str;
	i = 0;
	while (dst[i])
		i++;
	while (i >= 0)
	{
		if (dst[i] == (char)character)
			return ((char *)dst + i);
		i--;
	}
	return (NULL);
}
