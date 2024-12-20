/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:00 by kwillian          #+#    #+#             */
/*   Updated: 2024/12/20 17:26:45 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct datafile
{
	int		infile;
	int		outfile;
	char	**envp;
	char	**cmd1;
	char	**cmd2;
}	t_files;

void	ft_free_split(char *split, char *msg);
void	close_files(int *end, t_files file);
void	clearear(char **cmd);
void	check_file(int file);
void	child_two(int fd_read, t_files fd_write, char **cmd);
void	child_one(t_files fd_read, int fd_write, char **cmd, char *file_path);
void	checker(int argc, char **envp);
int		check_accessible(const char *path);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*get_directory_path(char *path);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);

#endif
