/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:40:23 by kwillian          #+#    #+#             */
/*   Updated: 2024/05/05 19:07:09 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static size_t	bytes_in_buffer;
	static size_t	current_position;
	ssize_t			bytes_read;
	size_t			i;

    i = 0;
    bytes_in_buffer = 0;
    current_position = 0;
	if (bytes_in_buffer > 0)
	{
		while (current_position < bytes_in_buffer && buffer[current_position] != '\n')
		{
			write(1, &buffer[current_position], 1);
			current_position++;
			i++;
		}
		if (current_position < bytes_in_buffer) {
			current_position++;
			char *line = (char *)malloc((i + 1) * sizeof(char));
			if (!line)
				return (NULL);
			write(1, "\n", 1);
			ft_strncpy(line, buffer, i);
			line[i] = '\0';
			return (line);
		}
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
		return (NULL);
	else if (bytes_read == 0)
		return (NULL);
	else
	{
		bytes_in_buffer = bytes_read;
		current_position = 0;
		return (get_next_line(fd));
	}
}
// int main()
// {
//     int fd;

//     fd = open("archive.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         write(1, "error", 5);
//         close(fd);
//     }

//     get_next_line(fd);

//     return (0);
// }
