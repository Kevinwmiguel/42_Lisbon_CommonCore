/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:47 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/09 21:25:51 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_one(int fd_read, int fd_write, char **cmd, char **envp)
{
    char *nova;

    dup2(fd_read, STDIN_FILENO);
    dup2(fd_write, STDOUT_FILENO);
    close(fd_read);
    close(fd_write);

    // Constrói o caminho completo para o comando
    nova = ft_strjoin("/bin/", cmd[0]);
    if (!nova)
    {
        perror("ft_strjoin: ");
        exit(1);
    }

    // Executa o comando com seus argumentos
    execve(nova, cmd, envp);

    // Caso execve falhe, imprime erro e libera memória
    perror("Execve: ");
    free(nova);
    exit(1);
}

void	child_two(int fd_read, int fd_write, char **cmd, char **envp)
{
    char *nova;

    dup2(fd_read, STDIN_FILENO);   // Redireciona stdin para o pipe
    dup2(fd_write, STDOUT_FILENO); // Redireciona stdout para o arquivo de saída
    close(fd_read);
    close(fd_write);

    // Constrói o caminho completo para o comando
    nova = ft_strjoin("/bin/", cmd[0]);
    if (!nova)
    {
        perror("ft_strjoin: ");
        exit(1);
    }

    // Executa o comando com seus argumentos
    execve(nova, cmd, envp);

    // Caso `execve` falhe
    perror("Execve: ");
    free(nova);
    exit(1);
}
