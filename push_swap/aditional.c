
#include "push_swap.h"

t_node *ft_lstnew2(int number, int idx)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return NULL;
    new_node->number = number;
    new_node->index = idx;
    new_node->costToPush = 0;
    new_node->upMedium = false;
    new_node->cheapest = false;
    new_node->target = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
void ft_lstadd_front2(t_node **lst, t_node *new_node)
{
    if (lst && new_node) {
        new_node->next = *lst;
        if (*lst)
            (*lst)->prev = new_node;
        *lst = new_node;
    }
}