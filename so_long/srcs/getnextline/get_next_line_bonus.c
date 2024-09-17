/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:23:28 by kwillian          #+#    #+#             */
/*   Updated: 2024/09/11 21:25:31 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	freefunc(char *buffer)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (buffer[j] != '\0')
	{
		if (n)
			buffer[i++] = buffer[j];
		if (buffer[j] == '\n')
			n = 1;
		buffer[j++] = '\0';
	}
	return (n);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			size;

	line = NULL;
	size = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE < 1)
	{
		while (buffer[fd][size])
			buffer[fd][size++] = '\0';
		return (NULL);
	}
	while (buffer[0] || (read(fd, buffer[fd], BUFFER_SIZE)) > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (freefunc(buffer[fd]))
			break ;
	}
	return (line);
}

// int main()
// {
//     int fd;
//     int fd2;
//     char *line;
//     char *line2;
//     fd = open("archive.txt", O_RDONLY);
//     fd2 = open("archive2.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         write(1, "error", 5);
//         return (1);
//     }
//	   while (1)
//	   {
//         line = get_next_line(fd);
//         line2 = get_next_line(fd2);
//		   printf("1 archieve %d");
//		   printf();
//     }
//     close(fd);
//     return (0);
// }
