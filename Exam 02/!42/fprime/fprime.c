#include <stdio.h>
#include <stdlib.h>

void    fprime(int nbr)
{
    long    number = nbr;
    int i;

    i = 2;

    if (number == 1)
    {
        printf("1");
        return;
    }
    while (number > 1)
    {
        if (number % i == 0)
        {
            number = number / i;
            printf("%d", i);
            if (number > 1)
                printf("*");    
        }
        else
            i++;
    }
}


int main(int argc, char **argv)
{
    if (argc == 2)
        fprime(atoi(argv[1]));
    printf("\n");
}