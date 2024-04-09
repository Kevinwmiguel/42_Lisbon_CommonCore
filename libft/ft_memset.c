void    *ft_memset(void *ptr, int value, size_t num)
{
    unsigned char *p = ptr;
    size_t  i;

    i = 0;
    while(i < num)
    {
        p[i] = (unsigned char)value;
        i++;
    }
    return ptr;
}