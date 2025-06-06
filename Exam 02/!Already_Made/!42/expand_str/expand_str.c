#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

void    expand_str(char *str)
{
    int i;

    i = 0;
while(str[i] != '\0')
{
    while (is_space(str[i]) && str[i])
        i++;
    while (!is_space(str[i]) && str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
    if (is_space(str[i]) && str[i] && str[i + 1 ] != '\0')
    {
        write(1, "   ", 3);
        i++;
    }
}
}

int main(int argc, char **argv)
{
    if (argc == 2)
        expand_str(argv[1]);
    write(1, "\n", 1);
}