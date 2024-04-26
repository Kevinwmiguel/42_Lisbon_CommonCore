#include "libft.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void static ft_putchar(char c)
{
    write(1, &c, 1);
}

void static ft_putstr(char *c)
{
    char    letter;
    int i;

    i = 0;
    while (c[i] != '\0')
    {
        letter = c[i];
        write(1, &letter, 1);
        i++;
    }
}

int ft_printf(const char *str, ...)
{
    va_list list;
    va_start(list, str);
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i - 1] == '%')
        {
            if (str[i] == 'c')
                ft_putchar( va_arg(list, int));
            if (str[i] == 's')
                ft_putendl_fd( va_arg(list, char *), 1);
            if (str[i] == 'd')
                ft_putnbr_fd( va_arg(list, int), 1);
            if (str[i] == 'p')
                ft_putnbr_fd( va_arg(list, int), 1);
            if (str[i] == 'u')
                ft_putnbr_fd( va_arg(list, int), 1);    
            if (str[i] == 'x')
                ft_putnbr_fd( va_arg(list, int), 1);
            if (str[i] == 'X')
                ft_putnbr_fd( va_arg(list, int), 1);
            if (str[i] == '%')
                ft_putnbr_fd( va_arg(list, int), 1);     
        }
        i++;
    }
    va_end(list);
    return 0;
}

// • %c Prints a single character. Check 
// • %s Prints a string (as defined by the common C convention). Check  
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number. Check 
// • %i Prints an integer in base 10. 
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.
int main()
{
    char i = '3';
    char *str = "string";
    int x = -958;

    printf("");
    ft_printf("This is a letter %c \n", i);
    ft_printf("This is a string %s \n", str);
    ft_printf("\nThis is a int nmb %d tentatdva", x);
    return 0;
}
