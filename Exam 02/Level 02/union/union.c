#include <unistd.h>

void    union(char *s1, char *s2)
{
    int i;
    int ascii[128] = {0};

    i = 0;
    while (s1[i])
    {
        if (!ascii[(int)s1[i]]) // Casting do caracter na posição i, em s1. Se for o caracter A, ele sera convertido para 65 e assim, a posicao a ser verificada no array de inteiros é a 65
        {
            ascii[(int)s1[i]] = 1;
            write(1, &s1[i], 1);
        }
        i++;
    }
    i = 0;
    while (s2[i])
    {
        if (!ascii[(int)s2[i]])
        {
            ascii[(int)s2[i]] = 1;
            write(1, &s2[i], 1);
        }
        i++;
    }

}

int main(int argc, char **argv)
{
    if (argc == 3)
        union(argv[1], argv[2]);
    write(1, "\n", 1);
}

/*

Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>

*/