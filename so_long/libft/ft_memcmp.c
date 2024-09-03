/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:02 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 14:59:51 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*p;
	unsigned char	*s;
	size_t			i;

	p = (unsigned char *)ptr1;
	s = (unsigned char *)ptr2;
	i = 0;
	while (i < num)
	{
		if (p[i] != s[i])
		{
			return (p[i] - s[i]);
		}
		i++;
	}
	return (0);
}
