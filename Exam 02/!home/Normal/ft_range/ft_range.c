#include <stdlib.h>

int *ft_range(int start, int end)
{
    int    *range;
    int    size;
    int    step;
    int    i;

    if (start <= end)
    {
        size = end - start + 1;
        step = 1;
    }
    else
    {
        size = start - end + 1;
        step = -1;
    }
    range = (int *)malloc(sizeof(int) * size);
    if (!range)
        return (0);
    i = 0;
    while (i < size)
    {
        range[i] = start;
        start += step;
        i++;
    }
    return (range);
}
