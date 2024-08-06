/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:28 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 14:09:07 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int charactere)
{
	char	*dst;

	dst = (char *)s;
	while (*dst)
	{
		if ((unsigned char)*dst == (unsigned char)charactere)
			return (dst);
		dst++;
	}
	if ((unsigned char)*dst == (unsigned char)charactere)
		return (dst);
	return (NULL);
}
