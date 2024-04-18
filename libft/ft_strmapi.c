/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 07:08:00 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/18 14:31:56 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	size;
	int		i;

	size = ft_strlen(s);
	new = malloc((size + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (s[++i])
		new[i] = f(i, s[i]);
	new[i] = '\0';
	return (new);
}

// int main()
// {
//     char string[] = "BOBALHAO";
//     char *nova_string;
//     nova_string = ft_strmapi(string, test);
//     printf("%s\n", nova_string);
//     free(nova_string);
//     return (0);
// }
