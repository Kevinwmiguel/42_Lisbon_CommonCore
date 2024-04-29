/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:21:54 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/29 21:04:08 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef libftprintf.h
# define libftprintf.h

# include <stdlib.h>
# include <unistd.h>

int ft_printf(const char *, ...);

void			ft_putnbr_fd(int n, int fd);
void            ft_putstr_fd(char *s, int fd);
void	        ft_putchar_fd(char c, int fd);
void	    ft_puthex(unsigned int n, char format);

#endif