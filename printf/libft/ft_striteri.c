/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:42:24 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/22 03:23:04 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
// #include <stdio.h>
// static void print_index_and_char(unsigned int index, char *c)
// {
//     printf("Index, %u, Char, %c\n", index, *c);
// }
// int main()
// {
//     char str[] = "Testezao";
//     ft_striteri(str, &print_index_and_char);
//     return (0);
// }
