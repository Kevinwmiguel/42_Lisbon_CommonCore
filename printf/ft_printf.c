#include "libft.h"
#include <stdarg.h>
#include <unistd.h>


static void ft_putchar(char c)
{
    write(1, &c, 1);
}

static void ft_putstr(char *str)
{
    while (*str)
    {
        ft_putchar(*str);
        str++;
    }
}

static void ft_putnbr(unsigned int n)
{
    if (n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
    else
        ft_putchar(n + '0');
}
static void ft_puthex(unsigned int n, char format)
{
    char *hex_digits = (format == 'X') ? "0123456789ABCDEF" : "0123456789abcdef";
    if (n >= 16)
    {
        ft_puthex(n / 16, format);
        ft_putchar(hex_digits[n % 16]);
    }
    else
        ft_putchar(hex_digits[n]);
}
static void ft_putnbr_hex_fd(unsigned long long nbr, int fd)
{
    char *hex_digits = "0123456789abcdef";
    if (nbr >= 16)
    {
        ft_putnbr_hex_fd(nbr / 16, fd);
        ft_putnbr_hex_fd(nbr % 16, fd);
    }
    else
        ft_putchar_fd(hex_digits[nbr], fd);
}

static int ft_printf_internal(const char *format, va_list args)
{
    int count = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                ft_putnbr(num);
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                if (num < 0)
                {
                    ft_putchar('-');
                    num = -num;
                }
                ft_putnbr(num);
            }
            else if (*format == 'x' || *format == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                ft_puthex(num, *format);
            }
            else if (*format == 'c')
            {
                char c = (char)va_arg(args, int);
                ft_putchar(c);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                ft_putstr(str);
            }
            else if (*format == 'p')
            {
                unsigned long long ptr_val = (unsigned long long)va_arg(args, void *);
                ft_putstr_fd("0x", 1); // Prefixo "0x" para indicar formato hexadecimal
                ft_putnbr_hex_fd(ptr_val, 1); // Imprime o valor do ponteiro em hexadecimal
            }
            else if (*format == '%')
            {
                ft_putchar('%');
            }
            else
            {
                ft_putchar('%');
                ft_putchar(*format);
            }
        }
        else
        {
            ft_putchar(*format);
        }
        format++;
        count++;
    }
    return count;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = ft_printf_internal(format, args);
    va_end(args);
    return count;
}
// int main()
// {
//     char i = 'C';
//     char *str = "palavra";
//     unsigned int x = -958;
//     int j = -2147483648;

//     ft_printf("FUNCAO FT_PRINTF\n");
//     ft_printf("This is a letter %c \n", i);
//     ft_printf("This is a string %s \n", str);
//     ft_printf("This is a pointer %p tentativa \n", &x);
//     ft_printf("This is a int nmb %d D \n", x);
//     ft_printf("This is a int nmb %i ssss \n", j);
//     ft_printf("This is a int nmb %x ssss \n", x);
//     ft_printf("This is a int nmb %X ssss \n", x);
//     ft_printf("This is a uns dec nbm %u ssss \n", x);
//     ft_printf("This is a porcent %% ssss \n");

//     printf("\nFUNCAO PRINT\n");
//     printf("This is a letter %c \n", i);
//     printf("This is a string %s \n", str);
//     printf("This is a pointer %p tentativa \n", &x);
//     printf("This is a int nmb %d D \n", x);
//     printf("This is a int nmb %i ssss \n", j);
//     printf("This is a int nmb %x ssss \n", x);
//     printf("This is a int nmb %X ssss \n", x);
//     printf("This is a uns dec nbm %u ssss \n", x);
//     printf("This is a porcent %% ssss \n");
//     return 0;
// }