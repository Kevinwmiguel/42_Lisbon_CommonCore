
#include "push_swap.h"
#include <stdbool.h>

t_node *ft_lstnew2(int number, int idx) {
    t_node *new_node;

    new_node = malloc(sizeof(t_node));
    if (new_node == NULL)
        return (NULL);

    new_node->index = idx;
    new_node->number = number;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void ft_lstadd_front2(t_node **lst, t_node *new) {

    if (new == NULL)
        return;

    new->next = *lst;
    if (*lst != NULL) {
        (*lst)->prev = new;
    }
    *lst = new;
}

void sort_three_numbers(t_node **a)
{
    t_node *biggerOne;

    biggerOne = findmax(*a);
    if (biggerOne == *a)
        ra(a);
    else if ((*a)->next == biggerOne)
        rra(a);
    if ((*a)->number > (*a)->next->number)
        sa(a);
}

//stacklen 2
//sort three 3
//sortstacks +
void stack_sort_ultimate(t_node **a, t_node **b)
{
    int len_a;

    len_a = stack_len(*a);
    if (len_a-- > 3 && !is_sorted(*a))
        pb(b, a);
    if (len_a-- > 3 && !is_sorted(*a))
        pb(b, a);
    while(len_a-- > 3 && !is_sorted(*a))
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    sort_three_numbers(a);
    while(*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    current_index(*a);
    min_on_top(a);
}

void current_index(t_node *stack)
{
    int i;
    int median;

    i = 0;
    if(!stack)
        return ;
    median = stack_len(stack) / 2;
    while(stack)
    {
        stack->index = i;
        if (i <= median)
            stack->upMedium = true;
        else
            stack->upMedium = false;
        stack = stack->next;
        ++i;
    }
}

static void set_target_a(t_node *a, t_node *b)
{
    t_node *current_b;
    t_node *target_node;
    long best_match_index;

    while(a)
    {
        best_match_index = LONG_MIN;
        current_b = b;
        while(current_b)
        {
            if (current_b->number < a->number && current_b->number > best_match_index)
            {
                best_match_index = current_b->number;
            }
            current_b = current_b->number;
        }
        if (best_match_index == LONG_MIN)
            a->target = find_max(b);
        else
            a->target = target_node;
        a = a->next;
    }
}


void cost_checker(t_node *a, t_node *b)
{
    int len_a;
    int len_b;

    len_a = stack_len(a);
    len_b = stack_len(b);
    while (a)
    {
        a->costToPush = a->index;
        if (!(a->upMedium))
            a->costToPush = len_a - (a->index);
        if (a->target->upMedium)
            a->costToPush = len_a - (a->index);
        else
            a->costToPush += len_b - (a->target->index);
        a = a->next;
    }
}

void cheaperONE(t_node *lst)
{
    long cheapest;
    t_node  *cheapest_node;

    if (!lst)
        return ;
    cheapest = LONG_MAX;
    while(lst)
    {
        if (lst->costToPush < cheapest)
        {
            cheapest = lst->costToPush;
            cheapest_node = lst;
        }
        lst = lst->next;
    }
    cheapest_node->chepeast = true;
}

void init_nodes_a(t_node *a, t_node *b)
{
    current_index(a);
    current_index(b);
    set_target_a(a, b);
    cost_checker(a, b);
    cheaperONE(a);
}