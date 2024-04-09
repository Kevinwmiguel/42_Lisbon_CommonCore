int ft_memcmp(const void * ptr1, const void *ptr2, size_t num)
{
    const unsigned char *p = ptr1;
    const unsigned char *s = ptr2;

    while(num > 0)
    {
        if (p[num - 1] < s[num - 1])
        {
            return -1;
        } else if(p[num - 1] > s[num - 1])
        {
            return 1;
        }
        num--;
    }
    return 0;
}