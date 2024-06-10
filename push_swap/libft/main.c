/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:08:20 by kwillian          #+#    #+#             */
/*   Updated: 2024/06/07 20:57:58 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Testes

// #include <stdio.h>
// #include <stdlib.h>
// #include "libft.h"

// void ft_lstfreeone(t_list *node)
// {
//     if (node)
//     {
//         free(node->content);
//         free(node);
//     }
// }


// // Função de mapeamento para ft_lstmap
// static void *map_func_lst(void *content)
// {
//     // Exemplo de função de mapeamento simples
//     return ft_strdup((char *)content);
// }

// // Função de mapeamento para ft_strmapi
// static char map_func(unsigned int index, char c)
// {
//     return c + 1; // Exemplo de função de mapeamento simples
// }

// // Função de iteração para ft_striteri
// static void iter_func(unsigned int index, char *c)
// {
//     *c = *c + 1; // Exemplo de função de iteração simples
// }

// // Função de liberação de conteúdo para ft_lstdelone
// static void del_func(void *content)
// {
//     free(content); // Exemplo de função de liberação de conteúdo simples
// }

// // Função de impressão de conteúdo para ft_lstiter
// static void print_content(void *content)
// {
//     printf("%s\n", (char *)content); // Exemplo de função de impressão de conteúdo simples
// }

// int main(void)
// {
//     // Test isalpha
//     printf("Is 'A' alpha? %d\n", ft_isalpha('A'));
//     printf("Is '5' alpha? %d\n", ft_isalpha('5'));
//     printf("Is ' ' alpha? %d\n", ft_isalpha(' '));

//     // Test isdigit
//     printf("Is '5' a digit? %d\n", ft_isdigit('5'));
//     printf("Is 'A' a digit? %d\n", ft_isdigit('A'));
//     printf("Is ' ' a digit? %d\n", ft_isdigit(' '));

//     // Test isalnum
//     printf("Is 'A' alphanumeric? %d\n", ft_isalnum('X'));
//     printf("Is 'A' alphanumeric? %d\n", ft_isalnum('3'));
//     printf("Is 'A' alphanumeric? %d\n", ft_isalnum(' '));

//     // Test isascii
//     printf("Is 65 ASCII? %d\n", ft_isascii(65));
//     printf("Is 65 ASCII? %d\n", ft_isascii(201));
//     printf("Is 65 ASCII? %d\n", ft_isascii(0));

//     // Test isprint
//     printf("Is 'A' printable? %d\n", ft_isprint('A'));
//     printf("Is 'A' printable? %d\n", ft_isprint(' '));
//     printf("Is 'A' printable? %d\n", ft_isprint('\t'));

//     // Test strlen
//     printf("Length of 'Hello': %zu\n", ft_strlen("Hello"));
//     printf("Length of 'Hello': %zu\n", ft_strlen("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"));

//     // Test memset
//     char str[10];
//     ft_memset(str, 'A', 5);
//     printf("memset result: %s\n", str);

//     // Test bzero
//     char str2[10];
//     ft_bzero(str2, 4);
//     printf("bzero result: %s\n", str2);

//     // Test memcpy
//     char dest[10];
//     char src[] = "Hello";
//     ft_memcpy(dest, src, 5);
//     printf("memcpy result: %s\n", dest);

//     // Test memmove
//     char dest2[10];
//     ft_memmove(dest2, src, 5);
//     printf("memmove result: %s\n", dest2);

//     // Test strlcpy
//     char dest3[10];
//     size_t result = ft_strlcpy(dest3, src, 5);
//     printf("strlcpy result: %s, bytes copied: %zu\n", dest3, result);

//     // Test strlcat
//     char dest4[10] = "Hello";
//     result = ft_strlcat(dest4, " World", 10);
//     printf("strlcat result: %s, total length: %zu\n", dest4, result);

//     // Test toupper
//     printf("toupper('a') = %c\n", ft_toupper('a'));

//     // Test tolower
//     printf("tolower('A') = %c\n", ft_tolower('A'));

//     // Test strchr
//     const char *str3 = "Hello";
//     printf("strchr('Hello', 'e') = %s\n", ft_strchr(str3, 'e'));

//     // Test strrchr
//     printf("strrchr('Hello', 'l') = %s\n", ft_strrchr(str3, 'l'));

//     // Test strncmp
//     const char *str4 = "apple";
//     const char *str5 = "app";
//     int n = 3;
//     printf("strncmp('apple', 'app', 3) = %d\n", ft_strncmp(str4, str5, n));

//     // Test memchr
//     const char *str6 = "Hello";
//     printf("memchr('Hello', 'l', 5) = %s\n", (char *)ft_memchr(str6, 'l', 5));

//     // Test memcmp
//     const char *str7 = "abc";
//     const char *str8 = "abd";
//     n = 3;
//     printf("memcmp('abc', 'abd', 3) = %d\n", ft_memcmp(str7, str8, n));

//     // Test strnstr
//     const char *big = "Hello World";
//     const char *little = "World";
//     printf("strnstr('Hello World', 'World', 11) = %s\n", ft_strnstr(big, little, 11));

//     // Test atoi
//     const char *num_str = "12345";
//     int num = ft_atoi(num_str);
//     printf("atoi('12345') = %d\n", num);

//     // Test calloc
//     int *arr = ft_calloc(5, sizeof(int));
//     printf("calloc result: %p\n", (void *)arr);

//     // Test strdup
//     const char *src_str = "Hello";
//     char *dup_str = ft_strdup(src_str);
//     printf("strdup result: %s\n", dup_str);
//     free(dup_str); // Remember to free the memory allocated by strdup

//     // Test ft_substr
//     const char *orig_str = "Hello World";
//     char *substr = ft_substr(orig_str, 6, 5);
//     printf("ft_substr result: %s\n", substr);
//     free(substr); // Remember to free the memory allocated by ft_substr

//     // Test ft_strjoin
//     const char *s1 = "Hello ";
//     const char *s2 = "World";
//     char *joined_str = ft_strjoin(s1, s2);
//     printf("ft_strjoin result: %s\n", joined_str);
//     free(joined_str); // Remember to free the memory allocated by ft_strjoin

//     // Test ft_strtrim
//     const char *trim_str = "  Hello World  ";
//     char *trimmed_str = ft_strtrim(trim_str, " ");
//     printf("ft_strtrim result: \"%s\"\n", trimmed_str);
//     free(trimmed_str); // Remember to free the memory allocated by ft_strtrim

//     // Test ft_split
//     const char *split_str = "Hello,World,How,Are,You";
//     char **split_arr = ft_split(split_str, ',');
//     printf("ft_split result:\n");
//     for (int i = 0; split_arr[i] != NULL; i++)
//     {
//         printf("%s\n", split_arr[i]);
//         free(split_arr[i]); // Remember to free the memory allocated by ft_split
//     }
//     free(split_arr); // Remember to free the memory allocated by ft_split

//     // Test ft_itoa
//     int num_to_convert = 12345;
//     char *itoa_str = ft_itoa(num_to_convert);
//     printf("ft_itoa result: %s\n", itoa_str);
//     free(itoa_str); // Remember to free the memory allocated by ft_itoa

//     // Test ft_strmapi
//     const char *str9 = "Hello";
//     char *mapped_str = ft_strmapi(str9, &map_func);
//     printf("ft_strmapi result: %s\n", mapped_str);
//     free(mapped_str); // Remember to free the memory allocated by ft_strmapi

//     // Test ft_striteri
//     char str10[] = "Hello";
//     ft_striteri(str10, &iter_func);
//     printf("ft_striteri result: %s\n", str10);

//     // Test ft_putchar_fd
//     ft_putchar_fd('H', 1);
//     printf("\n");

//     // Test ft_putstr_fd
//     ft_putstr_fd("Hello", 1);
//     printf("\n");

//     // Test ft_putendl_fd
//     ft_putendl_fd("Hello", 1);

//     // Test ft_putnbr_fd
//     ft_putnbr_fd(12345, 1);
//     printf("\n");

//     // Test ft_lstnew
//     t_list *new_node = ft_lstnew("Hello");
//     printf("ft_lstnew result: %s \n", (char *)new_node->content);

//     // Test ft_lstadd_front
//     t_list *list = ft_lstnew("World");
//     ft_lstadd_front(&list, ft_lstnew("Hello"));
//     printf("ft_lstadd_front result: %s\n", (char *)list->content);

//     // Test ft_lstsize
//     printf("ft_lstsize result: %d\n", ft_lstsize(list));

//     // Test ft_lstlast
//     printf("ft_lstlast result: %s\n", (char *)ft_lstlast(list)->content);

//     // Test ft_lstadd_back
//     ft_lstadd_back(&list, ft_lstnew("How"));
//     printf("ft_lstadd_back result: %s\n", (char *)ft_lstlast(list)->content);

//     // Test ft_lstiter
//     t_list *list3 = ft_lstnew("Hello");
//     ft_lstadd_back(&list3, ft_lstnew("World"));
//     printf("List contents before iteration:\n");
//     ft_lstiter(list3, &print_content);

//     // Test ft_lstmap
//     t_list *list4 = ft_lstnew("Goodbye");
//     ft_lstadd_front(&list4, ft_lstnew("Hellow"));
//     ft_lstadd_back(&list4, ft_lstnew("World1"));

    
//     printf("until here\n");

//     //Falta ft_lstnew e ft_lstdelone
//     return 0;
// }