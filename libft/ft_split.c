/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:59:58 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/11 11:17:47 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}	
	return (i);
}
char	**ft_split(char const *s, char c)
{
	int	count;
	int	i;
	int	j;
	char **nova;

	i = 0;
	j = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if(s[i] == c)
			count++;
		i++;
	}
	nova = (char **)malloc((count + 1) * sizeof(char *));
	if (!nova)
	{
		return (NULL);
	}
	i = 0;
	while (j < count)
	{
		i = 0;
		while (s[i] != c)
		{
			nova[j][i] = s[i];
			i++;
		}
		j++;
		nova[j][i] = '\0';
	}
	return (nova);
}
