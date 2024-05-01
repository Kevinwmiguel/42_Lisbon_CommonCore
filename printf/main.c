/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 15:12:58 by kwillian          #+#    #+#             */
/*   Updated: 2024/05/01 16:11:01 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int main()
{
    char i = 'C';
    char *str = "palavra";
    unsigned int x = -958;
    int j = -2147483648;
	int test = 0;
    ft_printf("FUNCAO FT_PRINTF\n");
    test = ft_printf("This is a letter %c \n", i);
    ft_printf("PONTUACAO PRINTF ANORMAL letter: %d\n", test);
    test = ft_printf("This is a string %s \n", str);
    ft_printf("PONTUACAO PRINTF ANORMAL string: %d\n", test);
    test = ft_printf("This is a pointer %p\n\n", &x);
	ft_printf("PONTUACAO PRINTF ANORMAL ponteiro: %d\n", test);
    test = ft_printf("This is a int nmb %d D \n", x);
    ft_printf("PONTUACAO PRINTF ANORMAL D: %d\n", test);
    test = ft_printf("This is a int nmb %i ssss \n", j);
    ft_printf("PONTUACAO PRINTF ANORMAL I: %d\n", test);
    test = ft_printf("This is a hexadecimal %x ssss \n", x);
    ft_printf("PONTUACAO PRINTF hexadecimal X: %d\n", test);
    test = ft_printf("This is a Chexadecimal %X ssss \n", x);
    ft_printf("PONTUACAO PRINTF Chexadecimal: %d\n", test);
    test = ft_printf("This is a uns dec nbm %u ssss \n", x);
    ft_printf("PONTUACAO PRINTF uns dec: %d\n", test);
    test = ft_printf("This is a porcent %% ssss \n");
    ft_printf("PONTUACAO PRINTF porcent: %d\n", test);
	test = ft_printf("%p", NULL);
    printf("\n");
    ft_printf("PONTUACAO PRINTF null: %d\n", test);
	test = ft_printf("%s", (char *)NULL);
    printf("\n");
    ft_printf("PONTUACAO PRINTF nil: %d\n", test);

    printf("------------------------------------");
    printf("FUNCAO PRINTF\n");
    test = printf("This is a letter %c \n", i);
    printf("PONTUACAO PRINTF ANORMAL letter: %d\n", test);
    test = printf("This is a string %s \n", str);
    printf("PONTUACAO PRINTF ANORMAL string: %d\n", test);
    test = printf("This is a pointer %p\n\n", &x);
	printf("PONTUACAO PRINTF ANORMAL ponteiro: %d\n", test);
    test = printf("This is a int nmb %d D \n", x);
    printf("PONTUACAO PRINTF ANORMAL D: %d\n", test);
    test = printf("This is a int nmb %i ssss \n", j);
    printf("PONTUACAO PRINTF ANORMAL I: %d\n", test);
    test = printf("This is a hexadecimal %x ssss \n", x);
    printf("PONTUACAO PRINTF hexadecimal X: %d\n", test);
    test = printf("This is a Chexadecimal %X ssss \n", x);
    printf("PONTUACAO PRINTF Chexadecimal: %d\n", test);
    test = printf("This is a uns dec nbm %u ssss \n", x);
    printf("PONTUACAO PRINTF uns dec: %d\n", test);
    test = printf("This is a porcent %% ssss \n");
    printf("PONTUACAO PRINTF porcent: %d\n", test);
	printf("%p \n", NULL);
	//printf("%s\n", (char *)NULL);
    // return 0;
}