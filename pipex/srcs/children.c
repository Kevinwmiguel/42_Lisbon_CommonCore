/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:43:47 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/10 22:11:25 by kwillian         ###   ########.fr       */
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
    if (ft_strncmp(cmd[0],"ls", 3))
        //Aqui o cmd devera receber o argumento como o nome do arquivo para que seja dado apenas um ls naquele arquivo.
        
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
