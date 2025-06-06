#include <unistd.h>
#include <stdlib.h>

int ft_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}

int ft_is_uppercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

char    *ft_to_lowercase(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_is_alpha(str[i]) && ft_is_uppercase(str[i]))
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}

void    ft_snake_to_camel(char *str)
{
    int i;

    i = 0;

    str = ft_to_lowercase(str);

    while (str[i])
    {
        if (str[i] == '_' && ft_is_alpha(str[i + 1]))
            str[i + 1] = str[i + 1] - 32; 
        i++;
    }
    i = 0;
    while (str[i])
    {
        if (str[i] == '_')
            i++;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_snake_to_camel(argv[1]);
    }
    write(1, "\n", 1);
}