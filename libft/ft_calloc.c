/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:48 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/19 20:17:59 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	size_t	i;
	void	*memo;

	i = 0;
	memo = malloc(num_elements * element_size);
	if (!memo)
		return (NULL);
	ft_bzero(memo, num_elements * element_size);
	return (memo);
}
