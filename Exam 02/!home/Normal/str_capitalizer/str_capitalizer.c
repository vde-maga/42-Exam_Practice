#include <unistd.h>

int is_alpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    return (0);
}

int is_uppercase(char c)
{
    if ((c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

char *ft_lowercase(char *str)
{
    int i;

    i = 0;

    while (str[i])
    {
        if (is_uppercase(str[i]))
        {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}

void    ft_capitalizer(char *str)
{
    int i;

    i = 0;

    str = ft_lowercase(str);
    while (str[i])
    {
        while (!(is_alpha(str[i])))
            i++;
        if (is_alpha(str[i]))
            str[i] = str[i] - 32;
        while (is_alpha(str[i]))
            i++;
    }
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            ft_capitalizer(argv[i]);
            ft_putstr(argv[i]);
            write (1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}