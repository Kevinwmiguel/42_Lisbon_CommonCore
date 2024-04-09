char	*ft_strchr(const char *str, int character)
{
    int	i;

	i = 0;
    while(str[i] != '\0')
	{
		if(str[i] == character)
    	{
			return (char *)&str[i];
    	}
		i++;
	}
	return NULL;
}