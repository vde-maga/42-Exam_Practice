int		max(int* tab, unsigned int len)
{
    int result;
    unsigned int i;

    i = 0;
    result = tab[0];

    while (tab && i < len)
    {
        if (result < tab[i])
            result = tab[i];
        i++;
    }

    return (result);
}


// #include <stdio.h>

// int main(void)
// {
//     int test1[] = {1, 2, 3, 4, 5};
//     printf("Numero maior: %d\n", max(test1, 2));
// }