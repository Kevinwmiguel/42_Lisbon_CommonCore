/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:55:56 by kwillian          #+#    #+#             */
/*   Updated: 2024/11/15 16:31:14 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 150
# endif

char	*get_next_line(int fd);
size_t	ft_strlen1(const char *s);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
