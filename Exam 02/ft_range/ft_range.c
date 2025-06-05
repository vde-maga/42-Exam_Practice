#include <stdlib.h>

int	absolute_number(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int     *ft_range(int start, int end)
{
	int	size = absolute_number(start - end) + 1;
	int	*range = (int *)malloc(sizeof(int) * (size));
	if (!range)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		if (start <= end)
			range[i] = start + i;
		else if (start > end)
			range[i] = start - i; 
		i++;
	}
	return (range);
}

/*

Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.

*/