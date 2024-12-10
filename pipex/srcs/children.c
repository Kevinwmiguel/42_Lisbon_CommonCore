/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:47 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/10 22:19:10 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(files fd_read, int fd_write, char **cmd, char *argv)
{
    char *nova;

    dup2(fd_read.infile, STDIN_FILENO);
    dup2(fd_write, STDOUT_FILENO);
    close(fd_read.infile);
    close(fd_write);

    // Constrói o caminho completo para o comando
    nova = ft_strjoin("/bin/", cmd[0]);
    if (!nova)
    {
        perror("ft_strjoin: ");
        exit(1);
    }
    if (ft_strncmp(cmd[0], "ls", 3) == 0)
    {
        // Se não houver argumentos após o comando 'ls', adiciona o nome do arquivo
        if (cmd[1] == NULL) // Caso sem argumentos
        {
            cmd[1] = argv;  // Adiciona o nome do arquivo (ou diretório)
            cmd[2] = NULL;   // Finaliza a lista de argumentos com NULL
        }
        else if (cmd[1] != NULL && access(argv , F_OK) == 0) // Verifica se o arquivo existe
        {
            // Adiciona o nome do arquivo ao final dos argumentos (caso já haja outros argumentos como '-l' ou '-a')
            size_t len = 0;
            while (cmd[len] != NULL)
                len++;  // Encontra o último índice da lista de argumentos
            cmd[len] = argv;  // Adiciona o nome do arquivo no final
            cmd[len + 1] = NULL; // Finaliza a lista de argumentos
        }
        else
        {
            // Caso o arquivo não exista, podemos fazer algum tratamento de erro se necessário
            fprintf(stderr, "Arquivo %s não encontrado\n", cmd[1]);
            free(nova);
            exit(1);
        }
    }
 
    // Executa o comando com seus argumentos
    execve(nova, cmd, fd_read.envp);

    // Caso execve falhe, imprime erro e libera memória
    perror("Execve: ");
    free(nova);
    exit(1);
}

void	child_two(int fd_read, files fd_write, char **cmd)
{
    char *nova;

    dup2(fd_read, STDIN_FILENO);   // Redireciona stdin para o pipe
    dup2(fd_write.outfile, STDOUT_FILENO); // Redireciona stdout para o arquivo de saída
    close(fd_read);
    close(fd_write.outfile);

    // Constrói o caminho completo para o comando
    nova = ft_strjoin("/bin/", cmd[0]);
    if (!nova)
    {
        perror("ft_strjoin: ");
        exit(1);
    }

    // Executa o comando com seus argumentos
    execve(nova, cmd, fd_write.envp);

    // Caso `execve` falhe
    perror("Execve: ");
    free(nova);
    exit(1);
}
