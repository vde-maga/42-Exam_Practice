#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

void rostring(char *str)
{
    int i = 0;
    int start_first = 0, end_first = 0;
    int printed_any = 0;

    // Pula os espaços iniciais para encontrar a primeira palavra.
    while (str[i] && is_space(str[i]))
        i++;
    start_first = i;
    while (str[i] && !is_space(str[i]))
        i++;
    end_first = i;

    /* 
       Agora, a partir da posição atual, iremos imprimir as demais palavras.
       A lógica é:
         - Pular os espaços.
         - Se houver uma palavra, se já imprimiu algo antes, imprime um espaço.
         - Imprimir a palavra.
    */
    while (str[i])
    {
        // Pula os espaços entre as palavras
        while (str[i] && is_space(str[i]))
            i++;
        // Se há uma palavra a seguir
        if (str[i])
        {
            if (printed_any)
                write(1, " ", 1);
            // Imprime a palavra atual
            while (str[i] && !is_space(str[i]))
            {
                write(1, &str[i], 1);
                i++;
            }
            printed_any = 1;
        }
    }

    // Se alguma palavra após a primeira foi impressa, insere um espaço antes de imprimir a primeira.
    if (printed_any)
        write(1, " ", 1);

    // Imprime a primeira palavra.
    i = start_first;
    while (i < end_first)
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc >= 2)
        rostring(argv[1]);
    write(1, "\n", 1);
    return 0;
}
