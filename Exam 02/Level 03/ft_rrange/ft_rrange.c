#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*dest;
	int	size;
	int	i;

	i = 0;
	if (end >= start)
		size = end - start + 1;
	else
		size = start - end + 1;
	dest = (int *)malloc(sizeof(int) * size);
	if (!dest)
		return (NULL);
	if (end >= start)
	{
		while (end >= start)
		{
			dest[i] = end;
			end--;
			i++;
		}
	}
	else
	{
		while (end <= start)
		{
			dest[i] = end;
			end++;
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int		*ft_rrange(int start, int end);

void	print_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d", arr[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

int	main(void)
{
	int	*arr;
	int	size;

	// Teste 1: (1, 3)
	arr = ft_rrange(1, 3);
	size = 3;
	printf("ft_rrange(1, 3): ");
	print_array(arr, size);
	free(arr);
	// Teste 2: (-1, 2)
	arr = ft_rrange(-1, 2);
	size = 4;
	printf("ft_rrange(-1, 2): ");
	print_array(arr, size);
	free(arr);
	// Teste 3: (0, 0)
	arr = ft_rrange(0, 0);
	size = 1;
	printf("ft_rrange(0, 0): ");
	print_array(arr, size);
	free(arr);
	// Teste 4: (0, -3)
	arr = ft_rrange(0, -3);
	size = 4;
	printf("ft_rrange(0, -3): ");
	print_array(arr, size);
	free(arr);
	return (0);
}
*/
/*
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int		*ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/