#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int	ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    last_word(char *str)
{
    int i;
    int last_word_length;
    int last_word_check;

    i = ft_strlen(str) - 1;
    last_word_length = 0;
    last_word_check = 0;

    while(is_space(str[i]) && last_word_check == 0)
            i--;
    while (!is_space(str[i]) && last_word_check == 0)
    {
        last_word_length++;
        i--;
    }
    if (is_space(str[i]) && last_word_check == 0)
    {
        last_word_check = 1;
        i++;
    }
    while (str[i] && !is_space(str[i]) && last_word_check == 1 && last_word_length != 0)
    {
        write(1, &str[i], 1);
        last_word_length--;
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        last_word(argv[1]);
    write(1, "\n", 1);
}