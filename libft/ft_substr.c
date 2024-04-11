char *ft_substr(char const *s, unsigned int start,size_t len)
{
    unsigned int    i;

    i = 0;
    char *nova = (char *)malloc(len + 1);
    if (!nova)
    {
        return NULL;
    }
    while(i < len && s[start + i] != '\0')
    {
        nova[i] = s[start + i];
        i++;
    }
    nova[i] = '\0';
    return nova;
}