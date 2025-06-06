#include <unistd.h>

void    ft_putnbr(int i)
{
    char    c;
    if (i > 9)
        ft_putnbr(i / 10);
    c = i % 10 + '0';
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        ft_putnbr(argc - 1);
    }
    else
    {
        write(1, "0", 1);
    }
    write(1, "\n", 1);

}