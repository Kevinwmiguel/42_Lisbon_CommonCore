/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:00:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/06/07 20:52:26 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "printf/ft_printf.h"
#include "libft/libft.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        //criacao das pilhas
        t_list **a;
        t_list b;

        //variaveis
        int comandos = argc;
        int i = 1;
        int j = argc;

        //criar o haed
        t_list *a = (t_list **)malloc(comandos * sizeof(t_list));
        
        //inserir na lista
        while (comandos > 1)
        {
            data = ft_atoi(argv[i]);
            t_list *temp = ft_lstnew(data);
            ft_lstadd_back(a,temp);
            i++;
            comandos--;
        }

        ft_lstiter(a, printf);
        
    }
    return (0);
}
