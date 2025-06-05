// #include <stdio.h>

// int		max(int* tab, unsigned int len)
// {
//     unsigned int max, i = 0;
//     while(*tab && i < len)
//         if (*tab > max) {max = *tab;}; tab++; i++;
//     return (max);
// }

// int main(void)
// {
//     int test[5] = {0,1,2,3,4};
//     unsigned int len = 3;
//     printf("%d\n", max(test, len));
// }

// int main() {
//     int array[] = {3, 5, 7, 2, 8, 4, 10, 12};
//     unsigned int len = 4;

//     int result = max(array, len);
//     printf("O maior valor no array é: %d\n", result);

//     return 0;
// }

//#include <stdio.h>

int max(int* tab, unsigned int len)
{
    if (len == 0) return 0; // Handle empty array case
    unsigned int i = 0;
    int max = tab[0]; // Initialize with the first element
    while (i < len)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        } 
        i++;
    }
    return (max);
}
/*
int main(void)
{
    int test[5] = {0, 1, 2, 3, 4};
    unsigned int len = 3;
    printf("%d\n", max(test, len)); // Correct output: 2
}
*/