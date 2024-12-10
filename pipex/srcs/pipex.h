/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:00 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/10 22:05:14 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_h
# define PIPEX_H

#include "../libft/libft.h"
#include <unistd.h>  // Para execve
#include <stdio.h>   // Para perror
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

typedef struct datafile
{
    /* data */
    int     infile;
    int     outfile;
    char    **envp;
} files;

void	ft_free_split(char **split);
void    closes(int end1, int end2,int infile, int outfile);
void    clearear(char **cmd1, char **cmd2);
void    check_file(int file);
void	child_two(int fd_read, files fd_write, char **cmd);
void	child_one(files fd_read, int fd_write, char **cmd, char *argv);
void    checker(int argc, char **envp);

#endif // DEBUG
