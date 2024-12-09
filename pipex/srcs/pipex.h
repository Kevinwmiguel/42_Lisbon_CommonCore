/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:00 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/09 20:49:22 by kwillian         ###   ########.fr       */
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

void	ft_free_split(char **split);
void    closes(int end1, int end2,int infile, int outfile);
void    clearear(char **cmd1, char **cmd2);
void    check_file(int file);
void	child_two(int fd_read, int fd_write, char **cmd, char **envp);
void	child_one(int fd_read, int fd_write, char **cmd, char **envp);
void    checker(int argc, char **envp);

#endif // DEBUG
