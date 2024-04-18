/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 08:55:16 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 08:56:30 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *s_find, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(s_find);
	if (n_len == 0)
		return ((char *)s);
	while (*s && len >= n_len)
	{
		if (ft_strncmp(s, s_find, n_len) == 0)
			return ((char *)s);
		s++;
		len--;
	}
	return (NULL);
}
