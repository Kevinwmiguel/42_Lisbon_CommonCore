void ft_bzero(void *s, size_t n)
{
    if (s != NULL)
    {
        unsigned char *ptr;
        size_t  i;

        i = 0;
        ptr = (unsigned char *)s;
        while(i < n)
        {
            ptr[i] = 0;
            i++;
        }
    }
}