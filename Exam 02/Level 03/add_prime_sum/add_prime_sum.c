#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int result;
    int signal;

    i = 0;
    result = 0;
    signal = 1;
    while (str[i] == ' ' && str[i] == '\t')
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

int is_prime(int nbr)
{
    int i;

    i = 2;
    if (nbr < 2)
        return (0);
    if (nbr % 2 == 0)
        return (1);
}

void    add_prime_sum(char *str)
{
    long    nbr = ft_atoi(str);
    long    result;
    long    i = 2;

    result = 0;

    if (nbr < 1)
    {
        write(1, "0", 1);
        return;
    }
    while (i <= nbr)
    {
        if ()
    }

}

int main(int argc, char **argv)
{
    if (argc == 2)
        add_prime_sum(argv[1]);
    write(1, "\n", 1);
}

/*

Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

*/