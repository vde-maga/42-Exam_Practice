#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int result;
    int signal;

    i = 0;
    result = 0;
    signal = 1;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '+' || str[i] == '-')
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

void    print_hex(int nbr)
{
    char *base = "0123456789abcdef";
    if (nbr > 16)
    {
        print_hex(nbr / 16);
        print_hex(nbr % 16);
    }
    if (nbr < 16)
        write(1, &base[nbr % 16], 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int number = ft_atoi(argv[1]);
        print_hex(number);
    }
    write(1, "\n", 1);
}