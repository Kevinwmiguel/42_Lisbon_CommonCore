/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/30 20:12:44 by kwillian         ###   ########.fr       */
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

check args()
{
	
}

void	child_one(int fd_write, char *cmd, char **envp)
{
	dup2(fd_write, STDOUT_FILENO);
	close(fd_write);
    char *args[] = {cmd, NULL};
	char *nova = ft_strjoin("/bin/", cmd);
    execve(nova, args, envp);
    perror("Execve: ");
    exit(1);
}

void	child_two(int fd_read, char *cmd, char **envp)
{
	dup2(fd_read, STDIN_FILENO);
	close(fd_read);
	char *args[] = {cmd, NULL};
	char *nova = ft_strjoin("/bin/", cmd);
	execve(nova, args, envp);
	perror("Execve: ");
	exit(1);
}

int main(int argc, char **argv, char **envp)
{
	int end[2];
    pid_t child1, child2;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: ./pipex infile <cmd1> <cmd2> outfile\n");
        return (1);
    }
    if (pipe(end) == -1)
    {
        perror("Pipe: ");
        return (1);
    }
    child1 = fork();
    if (child1 < 0)
        return (ft_printf("Fork: "));
    if (child1 == 0)
    {
        close(end[0]);               // Fecha leitura do pipe
        child_one(end[1], argv[1], envp); // Executa o primeiro comando
    }
    child2 = fork();
    if (child2 < 0)
        return (ft_printf("Fork: "));
    if (child2 == 0)
    {
        close(end[1]);               // Fecha escrita do pipe
        child_two(end[0], argv[2], envp); // Executa o segundo comando
    }
    close(end[0]);                   // Fecha o pipe no pai
    close(end[1]);
    waitpid(child1, NULL, 0);        // Espera os filhos terminarem
    waitpid(child2, NULL, 0);
    return (0);
}
