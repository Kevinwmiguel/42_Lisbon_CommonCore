void    *ft_memcpy(void *destination,const void *source, size_t num)
{
    unsigned char *p = destination;
    unsigned char *s = (unsigned char *)source;
    size_t  i = 0;

    while(i < num)
    {
        p[i] = s[i];
        i++;
    }
    return destination;
}