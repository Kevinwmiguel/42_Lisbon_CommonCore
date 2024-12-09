/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:03 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/09 21:34:07 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int end[2];
    pid_t child1, child2;
    int infile;
    int outfile;
    char **cmd1;
    char **cmd2;

    checker(argc, envp);
    infile = open(argv[1], O_RDONLY);
    check_file(infile);
    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    check_file(outfile);
    if (outfile < 0)
    {
        perror("Error to open outfile: \n");
        close(infile);
        return (1);
    }
    if (pipe(end) == -1)
    {
        perror("Error in Pipe: \n");
        close(infile);
        close(outfile);
        return (1);
    }

    child1 = fork();
    if (child1 < 0)
        return (fprintf(stderr, "Fork: child1 error\n"));
    if (child1 == 0)
    {
        close(end[0]); // Fecha leitura do pipe
        cmd1 = ft_split(argv[2], ' '); // Divide a string em um array de strings
        if (!cmd1)
        {
            perror("ft_split: ");
            return (1);
        }
        child_one(infile, end[1], cmd1, envp);
    }
    child2 = fork();
    if (child2 < 0)
        return (fprintf(stderr, "Fork: child2 error\n"));
    if (child2 == 0)
    {
        close(end[1]); // Fecha escrita do pipe
        cmd2 = ft_split(argv[3], ' '); // Divide a string em um array de strings
        if (!cmd2)
        {
            perror("ft_split: ");
            return (1);
        }
        child_two(end[0], outfile, cmd2, envp);
    }
    closes(end[0], end[1], infile, outfile);
    waitpid(child1, NULL, 0);
    waitpid(child2, NULL, 0);
    return (0);
}
