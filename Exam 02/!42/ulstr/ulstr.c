#include <unistd.h>

int is_lowecase(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_uppercase(char c)
{
    return (c >= 'A' && c <= 'Z');
}

void    ulstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (is_lowecase(str[i]))
            str[i] = str[i] - 32;
        else if(is_uppercase(str[i]))
            str[i] = str[i] + 32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        ulstr(argv[1]);
    write(1, "\n", 1);
}