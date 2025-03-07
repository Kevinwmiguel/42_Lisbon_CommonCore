/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:04:58 by thguimar          #+#    #+#             */
/*   Updated: 2025/02/20 22:04:13 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <strings.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;
//void
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int la, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
//size_t
size_t		ft_strlcat(char *dest, const char *src, size_t size);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
size_t		ft_strlen(const char *s);
//int
int			alpha_num(int c);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_tolower(int ch);
int			ft_toupper(int ch);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_atoi(const char *str);
int			ft_lstsize(t_list *lst);
int			ft_lstsize(t_list *lst);
//char
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_itoa(int n);
char		**ft_split(char *str, char c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strjoinsp(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
//t_list
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
