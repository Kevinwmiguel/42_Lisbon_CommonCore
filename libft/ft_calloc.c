/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:00:48 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:05:23 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_calloc(size_t num_elements, size_t element_size)
{
    size_t i;

    i = 0;
    void *memo = malloc(num_elements * element_size);
    if (!memo)
    {
        return NULL;
    }
    while(i < num_elements * element_size)
    {
        ((char *)memo)[i] = 0;
        i++;
    }
    return memo;
}