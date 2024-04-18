/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:46 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/13 19:03:40 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*nova;

	i = 0;
	nova = (char *)malloc(len + 1);
	if (!nova)
	{
		return (NULL);
	}
	while (i < len && s[start + i] != '\0')
	{
		nova[i] = s[start + i];
		i++;
	}
	nova[i] = '\0';
	return (nova);
}
