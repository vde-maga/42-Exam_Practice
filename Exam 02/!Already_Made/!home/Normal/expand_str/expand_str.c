#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

void expand_str(char *str)
{
    int i = 0;
    int j;

    while (str[i])
    {
        // Pula os espaços antes da palavra.
        while (str[i] && is_space(str[i]))
            i++;
        // Se chegou no fim, encerra.
        if (!str[i])
            break;
        // Imprime a palavra.
        while (str[i] && !is_space(str[i]))
        {
            write(1, &str[i], 1);
            i++;
        }
        // Usa j para checar se há outra palavra.
        j = i;
        while (str[j] && is_space(str[j]))
            j++;
        // Só imprime três espaços se houver outra palavra.
        if (str[j])
            write(1, "   ", 3);
        // Atualiza i para continuar a partir dos espaços ignorados.
        i = j;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        expand_str(argv[1]);
    write(1, "\n", 1);
    return 0;
}
