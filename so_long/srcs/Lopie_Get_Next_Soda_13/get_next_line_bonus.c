/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:46:45 by mmata-al          #+#    #+#             */
/*   Updated: 2024/04/10 13:34:57 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	shira[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*melon;
	int			soda;

	soda = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE < 1) //yes i know fd<0 is here twice, im lazy deal with it ahauwu
	{
		while (shira[fd][soda])
			shira[fd][soda++] = '\0';
		return (NULL);
	}
	melon = NULL;
	while (shira[fd][0] || read(fd, shira[fd], BUFFER_SIZE) > 0)
	{
		melon = ftstrjoin(melon, shira[fd]);
		if (clean_buff(shira[fd]))
			break ;
	}
	return (melon);
}

#include <fcntl.h>

int	main(void)
{
int	fd1;
int	fd2;
char	*line;
char	*line2;
int i = 1;
int j = 1;
fd1 = open("a.txt", O_RDONLY);
fd2 = open("b.txt", O_RDONLY);
while (1)
{
	line = get_next_line(fd1);
	line2 = get_next_line(fd2);
	printf("1 - Line %d:\n", i++);
	printf("-> %s\n", line);
	printf("2 - Line %d:\n", j++);
	printf("-> %s\n", line2);
	free(line);
	free(line2);
	if (!line || !line2)
		break ;
}
close(fd1);
close(fd2);
return (0);
}