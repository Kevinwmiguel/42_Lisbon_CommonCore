/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 07:08:00 by kwillian          #+#    #+#             */
/*   Updated: 2024/04/14 08:25:32 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char uppercase(unsigned int index, char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A'; // converte para maiúscula
    } else {
        return c; // mantém o caractere inalterado se não for uma letra minúscula
    }
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *new;
    size_t size;
    int i;

    size = ft_strlen(s) + 1;
    new = (char *)malloc((size + 1) * sizeof(char));
    if(!new)
    {
        return (NULL);
    }
    i = 0;
    new = ft_memmove(new, s, size);
    while(new[i++])
        new[i] = f(i, s[i]);
    return (new);
}

int main()
{
    char *string = "BOBALHAO";
    char *nova_string;
    
    nova_string = ft_strmapi(string, &uppercase);
    if (nova_string == NULL) {
        printf("Erro: alocação de memória falhou!\n");
        return 1;
    }
    free(nova_string);
    return (0);
}