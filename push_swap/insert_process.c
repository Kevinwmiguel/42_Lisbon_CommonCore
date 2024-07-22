#include "push_swap.h"

// Implementação da função free_split_args
void free_split_args(char **args)
{
    int i = 0;
    while (args[i]) {
        free(args[i]);
        i++;
    }
    free(args);
}

// Implementação da função is_number
bool is_number(const char *str)
{
    if (*str == '-' || *str == '+') str++;
    if (!*str) return false;
    while (*str) {
        if (*str < '0' || *str > '9') return false;
        str++;
    }
    return true;
}

// Implementação da função is_duplicate
bool is_duplicate(char **args, int number, int size)
{
    int i = 0;
    while (i < size) {
        int n = ft_atoi(args[i]);
        if (n == number) {
            return true;
        }
        i++;
    }
    return false;
}

// Implementação da função checkErrors
bool checkErrors(int argc, char *argv[])
{
    int n;
    int i = 1;
    if (argc == 2)
    {
        char **tokens = ft_split(argv[1], ' ');
        if (tokens == NULL)
            return (false);
        i = 0;
        while (tokens[i] != NULL)
        {
            if (!is_number(tokens[i]))
            {
                free_split_args(tokens);
                return (false);
            }
            n = ft_atoi(tokens[i]);
            if (n > INT_MAX || n < INT_MIN || is_duplicate(tokens, n, i))
            {
                free_split_args(tokens);
                return false;
            }
            i++;
        }
        free_split_args(tokens);
    }
    else
    {
        while (i < argc)
        {
            if (!is_number(argv[i]))
                return false;
            n = ft_atoi(argv[i]);
            if (n > INT_MAX || n < INT_MIN || is_duplicate(argv + 1, n, i - 1))
                return false;
            i++;
        }
    }
    return true;
}




void insert(t_node **a, long int data, int idx)
{
    t_node *new_node;
    
    new_node = ft_lstnew2(data, idx);
    if (new_node == NULL) {
        ft_printf("Erro de criação de novo nó\n");
        return;
    }
    ft_lstadd_front2(a, new_node);
}

void printa(t_node *a)
{
    t_node *current = a;
    int i = 1;
    while(current!= NULL)
    {
        ft_printf("A posiçao %d: %d \n", i, current->number);
        current = current->next;
        i++;
    };
}

void process_args(int argc, char *argv[], t_node **a, t_node **b) {
    int i = 1;
    if (argc > 2) {
        while (i < argc) {
            insert(a, ft_atoi(argv[i]), i - 1);
            i++;
        }
    } else if (argc == 2) {
        char **tokens = ft_split(argv[1], ' ');
        if (tokens == NULL)
            return;
        i = 0;
        while (tokens[i] != NULL) {
            insert(a, ft_atoi(tokens[i]), i);
            i++;
        }
        free_split_args(tokens);
    }
    printa(*a);
    pushT3ona(a, b);
    while (*b != NULL) {
        move_cheapest(a, b);
    }
    printa(*a);
    printa(*b);
}



