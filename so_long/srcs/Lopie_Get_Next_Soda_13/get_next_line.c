/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:57:39 by mmata-al          #+#    #+#             */
/*   Updated: 2024/10/11 22:49:36 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	shira[BUFFER_SIZE + 1];
	char		*melon;
	int			soda;

	soda = 0;
	if (fd < 0)
		return (NULL);
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		while (shira[soda])
			shira[soda++] = '\0';
		return (NULL);
	}
	melon = NULL;
	while (shira[0] || read(fd, shira, BUFFER_SIZE) > 0)
	{
		melon = ftstrjoin(melon, shira);
		if (clean_buff(shira))
			break ;
	}
	return (melon);
}
// int	main(void)
// {
// int		fd;
// char	*line;
// int i = 1;
// printf("FILE 1:\n");
// fd = open("a.txt", O_RDONLY);
// while (1)
// {
// 	line = get_next_line(-1);
// 	printf("Line %d", i++);
// 	printf("-> %s", line);
// 	free(line);
// 	if (!line)
// 		break ;
// }
// close(fd);
// i = 1;
// printf("\nFILE 2:\n");
// fd = open("b.txt", O_RDONLY);
// while (1)
// {
// 	line = get_next_line(fd);
// 	printf("Line %d", i++);
// 	printf("-> %s", line);
// 	free(line);
// 	if (!line)
// 		break ;
// }
// close(fd);
// i = 1;
// printf("\nCLOSED FILE:\n");
// fd = open("a.txt", O_RDONLY);
// close(fd);
// while (1)
// {
// 	line = get_next_line(fd);
// 	printf("Line %d", i++);
// 	printf("-> %s", line);
// 	free(line);
// 	if (!line)
// 		break ;
// }

// return (0);
// }
