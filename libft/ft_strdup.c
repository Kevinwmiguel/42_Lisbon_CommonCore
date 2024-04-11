size_t ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i]!= '\0')
        i++;
    return i;
}

char *strdup(const char *str)
{
    size_t i;
    size_t len;

    len = ft_strlen(str);
    i = 0;
    char *string = (char *)malloc(len + 1);
    if(!string)
        return NULL;
    while(i < len)
    {
        string[i] = str[i];
        i++;
    }
    string[len] = '\0';
    return (char *)string;
}