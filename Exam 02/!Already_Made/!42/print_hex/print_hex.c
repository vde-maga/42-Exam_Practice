#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int signal;
    int result;

    i = 0;
    signal = 1;
    result = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
        {
            signal = signal * -1;
            i++;
        }
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (result * signal);
}

void    print_hex(int number)
{
    char    *base = "0123456789abcdef";

    if (number >= 16)
        print_hex(number / 16);
    write(1, &base[number % 16], 1);

}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        long number = ft_atoi(argv[1]);
        if (number >= 0)
            print_hex(number);
    }
    write(1, "\n", 1);
}