#include <stdlib.h>

int	absolute_number(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int     *ft_rrange(int start, int end)
{
	int	size = absolute_number(start - end) + 1;
	int	*range = (int *)malloc(sizeof(int) * (size));
	if (!range)
		return (NULL);
	int i = 0;
	while (i < size)
	{
		if (end >= start)
			range[i] = end - i;
		else if (end < start)
			range[i] = end + i;
		i++;
	}
	return (range);
}
