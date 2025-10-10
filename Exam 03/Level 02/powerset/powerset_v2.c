#include <stdlib.h>
#include <stdio.h>

void	ft_populate_set(int *set, int len, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 2;
	while (i < len)
	{
		set[i] = atoi(argv[j]);
		i++;
		j++;
	}
}

void	ft_print_solution(int *set, int *used, int len)
{
	int	i;
	int	first_word_flag;

	i = 0;
	first_word_flag = 1;
	while (i < len)
	{
		if (used[i] == 1)
		{
			if (first_word_flag == 0)
				fprintf(stdout, " ");
			fprintf(stdout, "%d", set[i]);
			first_word_flag = 0;
		}
		i++;
	}
	fprintf(stdout, "\n");
	
}

void	ft_generate_powerset(int *set, int *used, int len, int original_number, int current_sum, int index)
{
	if (index == len)
	{
		if (current_sum == original_number)
			ft_print_solution(set, used, len);
		return;
	}

	ft_generate_powerset(set, used, len, original_number, current_sum, index + 1);
	used[index] = 1;
	ft_generate_powerset(set, used, len, original_number, current_sum + set[index], index + 1);
	used[index] = 0;
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	int	*set;
	int	*used;
	int	len;
	int	original_number;

	len = argc - 2;
	original_number = atoi(argv[1]);

	set = (int *)malloc(sizeof(int) * len);
	if (!set)
		return (1);
	ft_populate_set(set, len, argv);

	used = (int *)calloc(len, sizeof(int));
	if (!used)
	{
		free(set);
		return (1);
	}
	ft_generate_powerset(set, used, len, original_number, 0, 0);
	free(used);
	free(set);
	return (0);
}