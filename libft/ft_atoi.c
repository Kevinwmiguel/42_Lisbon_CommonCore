int ft_atoi(const char *str)
{
    int i;
    int ngt;
    int nmr;

    nmr = 0;
    ngt = 1;
    i = 0;
    while((str[i] >= 7 && str[i] <= 14) || str[i] == ' ' || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i]){
        ngt = -1;
        i++;
    }else if (str[i] == '+')
    {
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        nmr = nmr * 10 + (str[i] - '0');
        i++;
    }
    return nmr * ngt;
}