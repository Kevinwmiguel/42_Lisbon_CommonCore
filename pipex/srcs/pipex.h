/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 12:37:00 by kwillian          #+#    #+#             */
/*   Updated: 2025/02/09 17:03:53 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <unistd.h>
# include "../get_next_line/get_next_line.h"
# include <stdio.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct datafile
{
	int		infile;
	int		outfile;
	char	**envp;
	char	***cmds;
	int		cmd_count;
	int		pipe_fd[2];
}	t_files;

void	ft_free_split(char *split, char *msg);
void	close_files(int *end, t_files file);
int		check_infile(char *file);
void	child_two(int fd_read, t_files fd_write, char **cmd);
void	child_one(t_files fd_read, int fd_write, char **cmd, char *file_path);
void	checker(int argc, char **envp);
int		check_accessible(const char *path);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strcpy(char *dest, const char *src);
char	*get_directory_path(char *path);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t n);
char	**add_file_to_cmd(char **cmd, char *file_path);
size_t	length2(char *cmd);
size_t	length(char **cmd);

// new
void	free_split(char **split);
void	close_inout(t_files *file);
void	final_cleaner(t_files *file);

//path
void	path_cleaner(char **paths);
void	pick_path2(t_files *file, char **path, int cmd_index, int path_index);
char	**pick_path(char **envp);
void    search_path(t_files *file, char **paths);
void	pipex(int argc, char **argv, char **envp);
int		is_command(const char *arg);
int	here_doc(char *limiter);
void	handle_redirection_input(char **cmd_args);
#endif
