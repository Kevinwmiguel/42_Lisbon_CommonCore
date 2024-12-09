/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/09 19:12:46 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// # ./pipex infile cmd1 cmd2 outfile
// pipe()
//  |
//  |-- fork()
// 	  |
// 	  |-- child // cmd1
// 	  :     |--dup2()
// 	  :     |--close end[0]
// 	  :     |--execve(cmd1)
// 	  :
// 	  |-- parent // cmd2
// 			|--dup2()
// 			|--close end[1]
// 			|--execve(cmd2)
//
//  			 0         |     stdin     |  
// 						   -----------------    
// 				 1         |     stdout    |    
// 						   -----------------    
// 				 2         |     stderr    |  
// 						   -----------------
// 				 3         |     infile    |  // open()
// 						   -----------------
// 				 4         |     outfile   |  // open()
// 						   -----------------
// 				 5         |     end[0]    | 
// 						   -----------------
// 				 6         |     end[1]    |  
// 						   -----------------

void	child_one(int fd_read, int fd_write, char *cmd, char **envp)
{
    dup2(fd_read, STDIN_FILENO);   // Redireciona stdin para o arquivo de entrada
    dup2(fd_write, STDOUT_FILENO); // Redireciona stdout para o pipe
    close(fd_read);
    close(fd_write);
    char *args[] = {cmd, NULL};
    char *nova = ft_strjoin("/bin/", cmd);
    execve(nova, args, envp);
    perror("Execve: ");
    exit(1);
}

void	child_two(int fd_read, int fd_write, char *cmd, char **envp)
{
    dup2(fd_read, STDIN_FILENO);  // Redireciona stdin para o pipe
    dup2(fd_write, STDOUT_FILENO); // Redireciona stdout para o arquivo de saída
    close(fd_read);
    close(fd_write);
    char *args[] = {cmd, NULL};
    char *nova = ft_strjoin("/bin/", cmd);
    execve(nova, args, envp);
    perror("Execve: ");
    exit(1);
}

void    checker(int argc, char **envp)
{
    if (!envp)
    {
        ft_printf("Error\n No Path\n");
        exit(1);
    }
    if (argc != 5)
    {
        fprintf(stderr, "Usage: ./pipex infile <cmd1> <cmd2> outfile\n");
        exit(1);
    }
}

int main(int argc, char **argv, char **envp)
{
	int end[2];
    pid_t child1, child2;
    int infile, outfile;

    checker(argc, envp);
    infile = open(argv[1], O_RDONLY);
    if (infile < 0)
    {
        perror("Open infile: ");
        return (1);
    }
    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile < 0)
    {
        perror("Open outfile: ");
        close(infile);
        return (1);
    }
    if (pipe(end) == -1)
    {
        perror("Pipe: ");
        close(infile);
        close(outfile);
        return (1);
    }

    child1 = fork();
    if (child1 < 0)
        return (fprintf(stderr, "Fork: "));
    if (child1 == 0)
    {
        close(end[0]); // Fecha leitura do pipe
        child_one(infile, end[1], argv[2], envp);
    }

    child2 = fork();
    if (child2 < 0)
        return (fprintf(stderr, "Fork: "));
    if (child2 == 0)
    {
        close(end[1]); // Fecha escrita do pipe
        child_two(end[0], outfile, argv[3], envp);
    }
    close(end[0]); // Fecha o pipe no pai
    close(end[1]);
    close(infile);
    close(outfile);
    waitpid(child1, NULL, 0); // Espera os filhos terminarem
    waitpid(child2, NULL, 0);
    return (0);
}
