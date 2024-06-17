/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:03:15 by kwillian          #+#    #+#             */
/*   Updated: 2024/06/17 17:04:58 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

typedef struct node
{
    int number;
    struct node *next;
    struct node *prev;
} t_node;

#include "libft/libft.h" // Inclui a definição de t_list
# include "printf/ft_printf.h"

#endif