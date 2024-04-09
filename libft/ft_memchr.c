void  *ft_memchr(const void *ptr, int c, size_t n)
{
    const unsigned char *p;
    size_t  i;

    p = (const unsigned char *)ptr;
    i = 0;
    while(i < n)
    {
        if (p[i] == (unsigned char)c)
        {
            return &p[i];
        }
        i++;
    }
    return NULL;
}