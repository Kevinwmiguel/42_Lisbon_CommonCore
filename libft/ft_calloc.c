#include <stdlib.h>

void *ft_calloc(size_t num_elements, size_t element_size)
{
    size_t i;

    i = 0;
    void *memo = malloc(num_elements * element_size);
    if (!memo)
    {
        return NULL;
    }
    while(i < num_elements * element_size)
    {
        ((char *)memo)[i] = 0;
        i++;
    }
    return memo;
}