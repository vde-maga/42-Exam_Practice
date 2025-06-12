char    *ft_strrev(char *str)
{
    int i;
    int j;
    char temp;

    i = 0;
    j = ft_strlen(str) - 1;

    while (i < j)
    {
        temp = str[i];   // Armazena o caractere temporariamente
        str[i] = str[j]; // Troca os valores
        str[j] = temp;   // Finaliza a troca
        i++;
        j--;
    }
    return (str);
}


/*

Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str);

*/