
#include "push_swap.h"

typedef struct node
{
    int number;
    struct node *next;
    struct node *prev;
} t_node;

t_node *ft_lstnew2(int number)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (new_node == NULL)
        return NULL;

    new_node->number = number;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void	ft_lstadd_front2(t_node **lst, t_node *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}