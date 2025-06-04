/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 16:03:27 by joanda-s          #+#    #+#             */
/*   Updated: 2025/06/03 22:03:07 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

int	in_between(char c, char *str, int i)
{
	int	x;

	x = 0;
	while (str[i + x] && str[i + x] != c)
		x++;
	return (x);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*final;

	i = -1;
	j = -1;
	if (s1 != NULL && s2 != NULL)
		final = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 2);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	while (s1[++i] != '\0')
		final[i] = s1[i];
	final[i] = ' ';
	i++;
	while (s2[++j] != '\0')
		final[i++] = s2[j];
	final[i] = '\0';
	return (final);
}

int	varlen(char *str, int k)
{
	while (str[k] && str[k] != '$')
		k++;
	return (k);
}

int	pid_dollar(char *str, int j)
{
	int	x;

	j--;
	if (j < 0)
		return (0);
	x = 0;
	while (j >= 0 && str[j] == '$')
	{
		x++;
		j--;
	}
	return (x);
}

char	*expansions(char *argv, t_shell *utils, int pa)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		x;
	int		dollar;
	char	**split;
	char	*o_que_quiser;
	char	*o_que_quiser2;
	char	*o_que_quiser3;
	char	*o_que_quiser4;
	char	*o_que_quiser5;
	char	*output;
	char	*pid_str;

	i = 0;
	k = 0;
	l = 0;
	o_que_quiser3 = NULL;
	o_que_quiser4 = NULL;
	o_que_quiser5 = NULL;
	split = ft_split2(argv, ' ');
	o_que_quiser2 = NULL;
	dollar = 0;
	if (pa == 2)
		return (free_dptr(split, 0), ft_strdup(argv));
	while (split[i])
	{
		while (is_there_a_dollar(split[i]) != 0)
		{
			j = 0;
			while (split[i][j] && split[i][j] != '$')
				j++;
			x = j;
			if (split[i][j] == '$')
			{
				j++;
				if (split[i][j] == '$')
				{
					dollar = pid_dollar(split[i], j);
					if (dollar % 2 != 0)
						pid_str = ft_getpid();
					j++;
					o_que_quiser = ft_substr(split[i], 0, j - 2);
					o_que_quiser2 = ft_substr(split[i], j, ft_strlen(split[i]) - j);
					free(split[i]);
					o_que_quiser3 = ft_strjoin(o_que_quiser, pid_str);
					free(o_que_quiser);
					split[i] = ft_strjoin(o_que_quiser3, o_que_quiser2);
					free(o_que_quiser2);
					free(o_que_quiser3);
					free(pid_str);
				}
				else
				{
					k = j;
					while (ft_isalnum((int)split[i][k]) == 1)
						k++;
					o_que_quiser = ft_substr(split[i], j, k - j);
					while (utils->envr[l])
					{
						if (ft_strncmp(o_que_quiser, utils->envr[l], ft_strlen3(utils->envr[l])) == 0 && ft_strlen3(o_que_quiser) == ft_strlen3(utils->envr[l]))
							break ;
						l++;
					}
					if (utils->envr[l])
					{
						o_que_quiser2 = ft_substr(utils->envr[l], ft_strlen3(o_que_quiser) + 1, ft_strlen(utils->envr[l]) - ft_strlen(o_que_quiser) - 1);
						free(o_que_quiser);
						if (x != 0)
							o_que_quiser3 = ft_substr(split[i], 0, x);
						while (split[i][j])
							j++;
						o_que_quiser4 = ft_substr(split[i], k, j - k);
						o_que_quiser5 = ft_strjoin(o_que_quiser3, o_que_quiser2);
						free(o_que_quiser2);
						free(o_que_quiser3);
						o_que_quiser2 = ft_strjoin(o_que_quiser5, o_que_quiser4);
						free(o_que_quiser4);
						free(o_que_quiser5);
						free(split[i]);
						split[i] = ft_strdup(o_que_quiser2);
						free(o_que_quiser2);
					}
					else
					{
						o_que_quiser2 = ft_substr(split[i], 0, j - 1);
						o_que_quiser3 = ft_substr(split[i], k, ft_strlen(split[i]) - k);
						free(split[i]);
						split[i] = ft_strjoin(o_que_quiser2, o_que_quiser3);
						free(o_que_quiser);
						free(o_que_quiser2);
						free(o_que_quiser3);
					}
				}
			}
			l = 0;
		}
		i++;
	}
	i = 0;
	while (split[i])
	{
		if (i == 0)
		{
			output = ft_strjoinn(split[i], split[i + 1]);
			if (split[i + 1] == NULL)
				i += 1;
			else
				i += 2;
		}
		else
		{
			output = ft_strjoinn(output, split[i]);
			i++;
		}
	}
	free_dptr(split, 0);
	return (output);
}
