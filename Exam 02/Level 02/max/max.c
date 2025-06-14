int		max(int* tab, unsigned int len)
{

    if (len == 0)
        return (0);
    unsigned int    i;
    int result;

    i = 1; // Comecamos em um, porque ja copiamos o valor 0
    result = tab[0];
    while (i < len) // nao colocamos i <= len, pois iria aceder a elementos fora do array de inteiros
    {
        if (tab[i] > result)
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

/*

Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0.

*/