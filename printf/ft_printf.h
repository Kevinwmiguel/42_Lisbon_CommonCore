/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 06:48:06 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/30 18:26:59 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	    ft_putnbr_ptr_fd(unsigned long long nbr);
void	*ft_calloc(size_t num_elements, size_t element_size);
int	    ft_putstr_fd(char *s, int fd);
char	*ft_itoa(int n);
int	    ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);
int	    ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *str);
int ft_printf(const char *format, ...);

#endif