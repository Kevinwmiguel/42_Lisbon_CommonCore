/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:40:23 by kwillian          #+#    #+#             */
/*   Updated: 2024/05/09 01:58:08 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int freefunc(char *line, ssize_t bytes_read)
{
    if (bytes_read == -1 || (bytes_read == 0 && line[0] == '\0'))
	{
		free(line);
		return (1);
	}
    return (0);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*temp;
    char        *newline_pos;

	line = ft_strdup("");
    newline_pos = NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
        if ((newline_pos = ft_strchr(buffer, '\n')) || bytes_read > BUFFER_SIZE)
        {
            *newline_pos = '\n'; // Substitui o '\n' por '\0' para terminar a string antes do caractere de nova linha
            newline_pos++; // Move o ponteiro para o próximo caractere após '\n', que é o começo da próxima linha
            *newline_pos = '\0';
        }
		temp = line;
		line = ft_strjoin(temp, buffer);
		free(temp);
		if (newline_pos) // Se encontrou '\n', para de ler
			break;
	}
    bytes_read = freefunc(line, bytes_read);
    if (bytes_read > 0)
        return (NULL);
	return (line);
}

int main()
{
    int fd;
    char *line;
    fd = open("archive.txt", O_RDONLY);
    if (fd == -1)
    {
        write(1, "error", 5);
        return (1);
    }
    // while ((line = get_next_line(fd)) != NULL)
    // {
    //     write(1, line, ft_strlen(line));
    //     write(1, "\n", 1);
    //     free(line);
    // }
    line = get_next_line(fd);
    write(1, line, BUFFER_SIZE);
    // line = get_next_line(fd);
    // write(1, line, ft_strlen(line));
    // write(1, "\n", 1);
    // line = get_next_line(fd);
    // write(1, line, ft_strlen(line));
    // write(1, "\n", 1);
    // close(fd);
    return (0);
}
