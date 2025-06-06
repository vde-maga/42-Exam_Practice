#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

void rev_wstr(char *str)
{
    int length = ft_strlen(str);
    int end = length;
    int start;

    while (end >= 0)
    {
        if (is_space(str[end]) || end == 0)
        {
            start = (end == 0) ? 0 : end + 1;
            while (str[start] && !is_space(str[start]))
            {
                write(1, &str[start], 1);
                start++;
            }
            if (end > 0)
                write(1, " ", 1);
        }
        end--;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
}
