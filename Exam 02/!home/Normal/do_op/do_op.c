#include <stdio.h>
#include <stdlib.h>

void    do_op(char *s1, char *operator, char *s2)
{
    int number1 = atoi(s1);
    int number2 = atoi(s2);

    if (operator[0] == '-')
        printf("%d", (number1 - number2));
    else if (operator[0] == '+')
        printf("%d", (number1 + number2));
    else if (operator[0] == '*')
        printf("%d", (number1 * number2));
    else if (operator[0] == '/')
        printf("%d", (number1 / number2));
    else if (operator[0] == '%')
        printf("%d", (number1 % number2));
}

int main(int argc, char **argv)
{
    if (argc == 4)
    {
     do_op(argv[1], argv[2], argv[3]);
    }
    printf("\n");
}