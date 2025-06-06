#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int	number_length(long n)
{
	int i;

    i = 0;
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
    long    number;
    int i;
	char *dest;

    number = nbr;
	i = number_length(number);
    dest = (char *)malloc(sizeof(char) * (i + 1));
    
	if (!dest)
		return (NULL);
	dest[i--] = '\0';
	if (number == 0)
	{
		dest[0] = '0';
		return (dest);
	}
	if (number < 0)
	{
		dest[0] = '-';
		number = number * -1;
	}
	while (number)
	{
		dest[i] = (number % 10) + '0';
		number = number / 10;
		i--;
	}
	return (dest);
}
/*
int	main(void)
{
	char *test1 = ft_itoa(INT_MAX);
	printf("Teste 1 com o Numero: %d\n", INT_MAX);
	printf("Resultado: %s\n", test1);

	char *test2 = ft_itoa(INT_MIN);
	printf("Teste 2 com o Numero: %d\n", INT_MIN);
	printf("Resultado: %s\n", test2);

	char *test3 = ft_itoa(0);
	printf("Teste 3 com o Numero: %d\n", 0);
	printf("Resultado: %s\n", test3);

	char *test4 = ft_itoa(42);
	printf("Teste 4 com o Numero: %d\n", 42);
	printf("Resultado: %s\n", test4);

	char *test5 = ft_itoa(-42);
	printf("Teste 5 com o Numero: %d\n", -42);
	printf("Resultado: %s\n", test5);
}
*/