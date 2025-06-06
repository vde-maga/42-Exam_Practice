#include <stdio.h>
#include <stdlib.h>


void    fprime(int number)
{
    long nbr = number;

    int i = 2;
    if (nbr == 1)
    {
        printf("1");
        return;
    }
    while (number >= i)
    {
        if (number % i == 0)
        {
            printf("%d", i);
            if (number != i)
                printf("*");
            number = number / i;
            i = 2;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int number = atoi(argv[1]);
        fprime(number);
    }
    printf("\n");
}