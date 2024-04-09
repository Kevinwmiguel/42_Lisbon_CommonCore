void    *ft_memmove(void *destination,const void *source, size_t num)
{
    unsigned char *p = destination;
    unsigned char *s = source;
    
    if (p > s && p < s + num)
    {
        p += num;
        s += num;
        while(num--)
        {
            *p-- = *s--;
        }
    } else {
        while (num--)
        {
            *p++ = *s++;
        }
    }
    
    return destination;
}