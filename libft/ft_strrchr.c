/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:02:11 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 10:02:11 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
    int	i;

    i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}

char	*ft_strrchr(const char *str, int character)
{
    int	i;

	i = ft_strlen(str) - 1;
    while(i >= 0)
	{
		if(str[i] == character)
    	{
			return (char *)&str[i];
    	}
		i--;
	}
	return NULL;
}