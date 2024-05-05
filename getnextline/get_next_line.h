/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:40:32 by kwillian          #+#    #+#             */
/*   Updated: 2024/05/05 18:21:44 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 8

char *get_next_line(int fd);
size_t  ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char *ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strdup(const char *str);
char *ft_strndup(const char *s, size_t n);
char	*ft_strchr(const char *s, int charactere);

#endif
#endif

