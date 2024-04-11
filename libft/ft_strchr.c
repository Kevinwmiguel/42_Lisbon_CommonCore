/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:01:28 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:01:32 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int character)
{
    int	i;

	i = 0;
    while(str[i] != '\0')
	{
		if(str[i] == character)
    	{
			return (char *)&str[i];
    	}
		i++;
	}
	return NULL;
}