#include <stdio.h>
#include <stdlib.h>

int pdcd(int a, int b)
{
    int temp;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return (a);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int a = atoi(argv[1]);
        int b = atoi(argv[2]);
        printf("%d\n", pdcd(a, b));
    }
    else
        printf("\n");
}