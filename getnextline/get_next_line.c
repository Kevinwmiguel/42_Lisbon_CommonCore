/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:40:23 by kwillian          #+#    #+#             */
/*   Updated: 2024/05/07 18:04:08 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char *line = ft_strdup(""); // Inicializa a linha como uma string vazia
    static char buffer[1]; // Buffer temporário para ler um caractere por vez
    ssize_t bytes_read;

    while ((bytes_read = read(fd, buffer, 1)) > 0)
	{
        if (buffer[0] == '\n')
		{
            break; // Encerra o loop se encontrarmos uma quebra de linha
        }
        char *temp = line;
        line = ft_strjoin(temp, buffer); // Adiciona o caractere lido à linha
        free(temp);
    }

    if (bytes_read == -1 || (bytes_read == 0 && line[0] == '\0'))
	{
        free(line); // Libera a memória alocada se ocorrer um erro ou se chegarmos ao final do arquivo
        return NULL;
    }

    return line;
}
// int main()
// {
//     int fd;
//     char *line;

//     fd = open("archive.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         write(1, "error", 5);
//         return (1);
//     }

//     while ((line = get_next_line(fd)) != NULL)
//     {
//         write(1, line, ft_strlen(line));
//         write(1, "\n", 1);
//         free(line);
//     }
// 	line = get_next_line(fd);
// 	write(1, line, ft_strlen(line));
// 	write(1, "\n", 1);
// 	line = get_next_line(fd);
// 	write(1, line, ft_strlen(line));
// 	free(line);
//     close(fd);

//     return (0);
// }
