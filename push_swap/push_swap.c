/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwillian <kwillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 07:00:13 by kwillian          #+#    #+#             */
/*   Updated: 2024/06/27 05:32:14 by kwillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" // Inclui a definição de t_node
#include <stdio.h>

#include "libft/libft.h" 
# include "printf/ft_printf.h"

int mymax(t_node *lst)
{
    int temp;

    temp = lst->number;
    while(lst != NULL)
    {
        if (lst->number > lst->next->number)
            temp = lst->number;
        lst = lst->next;
    }
    if (lst->number < lst->prev->number)
        temp = lst->number;

    return temp;
}

int mymin(t_node *lst)
{
    int temp;

    temp = lst->number;
    while(lst != NULL)
    {
        if (lst->number > lst->next->number)
            temp = lst->number;
        lst = lst->next;
    }
    if (lst->number < lst->prev->number)
        temp = lst->number;
    
    return temp;
}

// void push2onb(t_node **a, t_node **b)
// {
//     int smaller;
//     int bigger;
//     t_node *new_node = NULL;
    
//     // pegar o maior valor e colocar em b
//     bigger = mymax(a);
//     // pegar o menor valor e colocar em b
//     smaller = mymin(a);


    

//     new_node = ft_lstnew2(bigger);
//     ft_lstadd_front2(&b, new_node);
//     new_node = ft_lstnew2(smaller);
//     ft_lstadd_front2(&b, new_node);
// }

// int is_sorted(t_node *a)
// {
//     while (a != NULL && a->next != NULL)
//     {
//         if (a->number > a->next->number)
//             return 0;
//         a = a->next;
//     }
//     return 1;
// }

// void simple_sort(t_node **a, t_node **b)
// {
//     while (!is_sorted(*a))
//     {
//         if ((*a)->number > (*a)->next->number)
//         {
//             sa(*a);
//             ft_printf("sa\n");
//         }
//         else
//         {
//             pb(a, b);
//             ft_printf("pb\n");
//         }
//     }
//     while (*b != NULL)
//     {
//         pa(a, b);
//         ft_printf("pa\n");
//     }
// }

// void free_list(t_node *head)
// {
//     t_node *current = head;
//     t_node *next;
//     while (current != NULL)
//     {
//         next = current->next;
//         free(current);
//         current = next;
//     }
// }

void insert(t_node **a, int data) {
    t_node *new_node = ft_lstnew2(data);
    if (new_node == NULL) {
        printf("Erro de criação de novo nó\n");
        return;
    }
    ft_lstadd_front2(a, new_node);
}
int main(int argc, char **argv) {
    t_node *a = NULL;
    t_node *b = NULL;
    int i = 1;

    // Recebe os valores na pilha A
    while (i < argc) {
        insert(&a, atoi(argv[i]));
        i++;
    }

    //MAx MIN
    //CHamar funcao aqui de max e mim
    // Move o topo da pilha A para a pilha B
    pb(&a, &b);
    pb(&a, &b);
    pb(&a, &b);
    
    // Mostra a pilha A
    printf("Pilha A:\n");
    t_node *temp = a;
    while (temp != NULL) {
        printf("%d\n", temp->number);
        temp = temp->next;
    }

    // Mostra a pilha B
    printf("Pilha B:\n");
    temp = b;
    while (temp != NULL) {
        printf("%d\n", temp->number);
        temp = temp->next;
    }

    // Liberação de memória (para evitar vazamentos)
   
     while (a != NULL) {
        temp = a;
        a = a->next;
        free(temp);
    }
    while (b != NULL) {
        temp = b;
        b = b->next;
        free(temp);
    }
    return 0;
}