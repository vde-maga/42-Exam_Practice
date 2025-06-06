#include <unistd.h>
#include <stdlib.h>

int is_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

void    camel_to_snake(char *str)
{
    int i;

    i = 0;

    while (str[i])
    {
        if (is_uppercase(str[i]))
        {
            write(1, "_", 1);
            str[i] = str[i] + 32;
        }
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        camel_to_snake(argv[1]);
    write(1, "\n", 1);
}