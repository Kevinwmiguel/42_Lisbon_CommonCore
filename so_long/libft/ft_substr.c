/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:46 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/26 13:28:06 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	j;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = (unsigned int)ft_strlen((char *)s);
	j = start;
	if (j >= i || len == 0)
		return (NULL);
	if (len > i - start)
		len = i - start;
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + j, len + 1);
	return (dst);
}
