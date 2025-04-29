/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:24:09 by thguimar          #+#    #+#             */
/*   Updated: 2024/08/30 16:23:22 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;

	
	str = (char *)malloc(sizeof(*s) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	if (i != 0)
		str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	printf("%s", ft_strdup("apenas testando se funciona"));

}*/
