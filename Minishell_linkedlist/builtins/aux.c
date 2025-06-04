/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:56:34 by thguimar          #+#    #+#             */
/*   Updated: 2025/06/04 00:49:19 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/builtins.h"

void	ft_free_pid(char **pid)
{
	int	i;

	i = 0;
	if (*pid == NULL)
		return ;
	while (pid[i])
	{
		free(pid[i]);
		i++;
	}
	free(pid);
}

char	*ft_getpid(void)
{
	char		*pid;
	int			fd;
	char		**temp;

	fd = open("/proc/self/stat", O_RDONLY);
	if (!fd)
		return (NULL);
	pid = get_next_line(fd);
	if (!pid)
		return (NULL);
	temp = ft_split(pid, ' ');
	free(pid);
	if (!temp)
		return (NULL);
	pid = ft_strdup(temp[0]);
	ft_free_pid(temp);
	if (!pid)
		return (NULL);
	return (pid);
}

char	*ft_strrstr(const char *haystack, const char *needle)
{
	char	*last_occurrence;
	size_t	needle_len;

	last_occurrence = NULL;
	if (!haystack || !needle)
		return (NULL);
	needle_len = ft_strlen(needle);
	while (*haystack)
	{
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			last_occurrence = (char *)haystack;
		haystack++;
	}
	return (last_occurrence);
}

char	*trim_start(char *str)
{
	int		i;
	int		j;
	char	*trimmed;

	i = 0;
	j = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	trimmed = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!trimmed)
		return (NULL);
	while (str[i])
	{
		trimmed[j] = str[i];
		i++;
		j++;
	}
	trimmed[j] = '\0';
	return (trimmed);
}
