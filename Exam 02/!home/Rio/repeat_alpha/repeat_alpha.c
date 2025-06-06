#include <unistd.h>

int is_lowercase(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

void    repeat_alpha(char *str)
{
    int i;
    int repeat;

    i = 0;
    repeat = 0;
    

    while (str[i])
    {
        if (is_lowercase(str[i]))
            repeat = str[i] - 'a' + 1;
        else if (is_uppercase(str[i]))
            repeat = str[i] - 'A' + 1;
        else
            repeat = 1;
        while (repeat)
        {
            write(1, &str[i], 1);
            repeat--;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        repeat_alpha(argv[1]);
    write(1, "\n", 1);
}