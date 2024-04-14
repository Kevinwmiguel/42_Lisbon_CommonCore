/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 07:08:00 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/14 11:16:16 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    char *new;
    size_t size;
    int i;

    size = ft_strlen(s);
    new = malloc((size + 1) * sizeof(char));
    if(!new)
        return (NULL);
    i = -1;
    while(s[++i])
        new[i] = f(i, s[i]);
    return (new);
}

int main()
{
    char string[] = "BOBALHAO";
    char *nova_string;
    nova_string = ft_strmapi(string, test);
    printf("%s\n", nova_string);
    free(nova_string);
    return (0);
}


void list() {
    t_list *test;


    while (!test->next)
    {
        test = test->next;    
    }
}
