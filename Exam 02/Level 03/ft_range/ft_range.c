#include <stdlib.h>

int	ft_size(int start, int end)
{
	int	result;

	result = 0;
	// fazemos este check, pois os numeros recebidos, podem ser negativos, ja que -2 e maior que -10
	if (start <= end)
		result = end - start + 1; // 10 - 2 = 8 e colocamos + 1, para ja comecar a contar o primeiro numero
	else
		result = start - end + 1;
	return (result);
}

int	*ft_range(int start, int end)
{
	int	*dest;
	int	size;
	int	i;

	size = ft_size(start, end);
	dest = (int *)malloc(sizeof(int) * size); // array de inteiros nao tem nulo
	if (!dest)
		return (NULL);
	i = 0;
	if (start <= end) // Numeros positivos
	{
		while (start <= end)
		{
			dest[i] = start;
			start++;
			i++;
		}
	}
	else // Numeros Negativos
	{
		while (start >= end)
		{
			dest[i] = start;
			start--;
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	int	*test;
	int	size;
	int	i;

	test = ft_range(2, 10);
	size = ft_size(2, 10);
	i = 0;
	while (i < size)
	{
		printf("Na Posicao de %d do Array de Inteiros, temos o Numero %d\n", i,
			test[i]);
		i++;
	}
}
*/
/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int	*ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/