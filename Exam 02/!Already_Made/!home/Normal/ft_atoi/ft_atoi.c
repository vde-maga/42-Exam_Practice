int	ft_atoi(const char *str)
{
    int i;
    int result;
    int signal;

    i = 0;
    result = 0;
    signal = 1;

    while (str[i] == ' ' && str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signal = signal * -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * signal);
}