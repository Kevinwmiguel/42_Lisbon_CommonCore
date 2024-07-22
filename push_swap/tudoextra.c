#include "push_swap.h"

int stack_len(t_node *stack)
{
    int len = 0;
    while (stack != NULL)
    {
        len++;
        stack = stack->next;
    }
    return len;
}

void set_target_a(t_node *a, t_node *b)
{
    t_node *current_a = a;
    while (current_a != NULL)
    {
        t_node *current_b = b;
        t_node *best_target = NULL;

        while (current_b != NULL)
        {
            if (current_b->number < current_a->number)
                if (best_target == NULL || current_b->number > best_target->number)
                    best_target = current_b;
            current_b = current_b->next;
        }
        if (best_target == NULL)
        {
            current_b = b;
            best_target = current_b;
            while (current_b != NULL) {
                if (current_b->number < best_target->number) {
                    best_target = current_b;
                }
                current_b = current_b->next;
            }
        }
        current_a->target = best_target;
        current_a = current_a->next;
    }
}


// void min_on_top(t_node **a)
// {
//     if (*a == NULL) return;

//     t_node *min_node = *a;
//     t_node *current = *a;
//     while (current != NULL)
//     {
//         if (current->number < min_node->number)
//             min_node = current;
//         current = current->next;
//     }

//     while (*a != min_node)
//         ra(a);  // Rotaciona a pilha até o menor elemento estar no topo
// }

// t_node *mymin(t_node *b)
// {
//     long int temp;
//     t_node *min_t_node;

//     if(!b)
//         return (NULL);
//     temp = LONG_MAX;
//     while (b)
//     {
//         if (b->number < temp)
//         {
//             temp = b->number;
//             min_t_node = b;
//         }
//         b = b->next;
//     }
//     return (min_t_node);
// }
// t_node *mymax(t_node *b)
// {
//     long int temp;
//     t_node *max_t_node = NULL;

//     if (!b)
//         return NULL;

//     temp = INT_MIN;
//     while (b != NULL)
//     {
//         if (b->number > temp)
//         {
//             temp = b->number;
//             max_t_node = b;
//         }
//         b = b->next;
//     }
//     return max_t_node;
// }

// void sort_three_numbers(t_node **a)
// {
//     t_node *max_node = mymax(*a);

//     if ((*a)->number == max_node->number)
//         ra(a);
//     else if ((*a)->next->number == max_node->number)
//         rra(a);

//     if ((*a)->number > (*a)->next->number)
//         sa(*a);
// }

// //stacklen 2
// //sort three 3
// //sortstacks +

void cost_checker(t_node *a, t_node *b) {
    int len_a = stack_len(a);
    int len_b = stack_len(b);

    while (a) {
        a->costToPush = a->index;
        if (!a->upMedium)
            a->costToPush = len_a - a->index;
        if (a->target->upMedium)
            a->costToPush += a->target->index;
        else
            a->costToPush += len_b - a->target->index;
        a = a->next;
    }

    while (b) {
        b->costToPush = b->index;
        if (!b->upMedium)
            b->costToPush = len_b - b->index;
        if (b->target->upMedium)
            b->costToPush += b->target->index;
        else
            b->costToPush += len_a - b->target->index;
        b = b->next;
    }
}

void cheaperONE(t_node *lst) {
    long cheapest = LONG_MAX;
    t_node *cheapest_node = NULL;

    while (lst) {
        if (lst->costToPush < cheapest) {
            cheapest = lst->costToPush;
            cheapest_node = lst;
        }
        lst = lst->next;
    }
    if (cheapest_node)
        cheapest_node->cheapest = true;
}


// void init_nodes_a(t_node *a, t_node *b)
// {
//     current_index(a);
//     current_index(b);
//     set_target_a(a, b);
//     cost_checker(a, b);
//     cheaperONE(a);
// }