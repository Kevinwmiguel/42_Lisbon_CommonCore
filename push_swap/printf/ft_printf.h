/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 06:48:06 by kwillian          #+#    #+#             */
/*   Updated: 2024/06/10 17:49:24 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_putnbr_ptr_fd(unsigned long long nbr);
int		ft_putstr_fd2(char *s, int fd);
int		ft_putnbr_fd2(int n, int fd);
size_t	ft_strlen2(const char *str);
int		ft_putchar_fd2(char c, int fd);
int		ft_printf(const char *format, ...);

#endif
