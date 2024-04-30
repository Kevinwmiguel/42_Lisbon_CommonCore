#include "ft_printf.h"
# include <stdio.h>

int main()
{
    char i = 'C';
    char *str = "palavra";
    unsigned int x = -958;
    int j = -2147483648;

    ft_printf("FUNCAO FT_PRINTF\n");
    ft_printf("This is a letter %c \n", i);
    ft_printf("This is a string %s \n", str);
    ft_printf("This is a pointer %p tentativa \n", &x);
    ft_printf("This is a int nmb %d D \n", x);
    ft_printf("This is a int nmb %i ssss \n", j);
    ft_printf("This is a int nmb %x ssss \n", x);
    ft_printf("This is a int nmb %X ssss \n", x);
    ft_printf("This is a uns dec nbm %u ssss \n", x);
    ft_printf("This is a porcent %% ssss \n");
	ft_printf("%p \n", NULL);
	ft_printf("%s \n", (char *)NULL);
	

    printf("\nFUNCAO PRINT\n");
    printf("This is a letter %c \n", i);
    printf("This is a string %s \n", str);
    printf("This is a pointer %p tentativa \n", &x);
    printf("This is a int nmb %d D \n", x);
    printf("This is a int nmb %i ssss \n", j);
    printf("This is a int nmb %x ssss \n", x);
    printf("This is a int nmb %X ssss \n", x);
    printf("This is a uns dec nbm %u ssss \n", x);
    printf("This is a porcent %% ssss \n");
	printf("%p \n", NULL);
	printf("%s\n", (char *)NULL);
	printf("% %s %s", str);
	printf("% %s %p", str);
    return 0;
}