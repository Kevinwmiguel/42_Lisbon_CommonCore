#include "push_swap.h"

void checkErrors(t_node **a, char *argv[])
{
    long n;
    int i;

    i = 0;
    while(argv[i])
    {
        n = ft_atoi(argv[1]);
        if (n > INT_MAX || n < INT_MIN)
            free_list(a);
        i++;
    }
}

void insert(t_node **a, long int data, int idx)
{
    t_node *new_node;
    
    new_node = ft_lstnew2(data, idx);
    if (new_node == NULL) {
        printf("Erro de criação de novo nó\n");
        return;
    }
    ft_lstadd_front2(a, new_node);
}
void process_args(int argc, char *argv[], t_node **a, t_node **b)
{
    long int i = 1;
    if (argc > 2) {
        while (i < argc) {

            // checar duplicado
            // checar erro de escrita
            insert(a, ft_atoi(argv[i]), i - 1);
            i++;
        }
        
    }
    else if (argc == 2)
    {
        char **tokens = ft_split(argv[1], ' ');
        if (tokens == NULL)
            return;
        i = 0;
        while (tokens[i] != NULL) {
            insert(a, ft_atoi(tokens[i]), i);
            free(tokens[i]);
            i++;
        }
        free(tokens);
    }
    pushT3ona(&(*a), &(*b));
}
