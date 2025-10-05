#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_swap(char *a, char *b)
{
	char tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_str(char *str, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			if (str[j] > str[j + 1])
				ft_swap(&str[j], &str[j + 1]);
			j++;
		}
		i++;
	}
}

void	ft_generate_permutation(char *set, char *permutation, int *used, int len, int depth)
{
	if (depth == len)
	{
		write(1, permutation, len);
		write(1, "\n", 1);
		return;
	}
	int	i;

	i = 0;
	while (i < len)
	{
		if (used[i] == 0)
		{
			permutation[depth] = set[i];
			used[i] = 1;
			ft_generate_permutation(set, permutation, used, len, depth + 1);
			used[i] = 0;
		}
		i++;
	}
}


int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
		return (1);

	int	len;
	char	*sorted_argument;
	char	*current_perm;
	int	*used_flag;
	int	i;

	len = ft_strlen(argv[1]);


	sorted_argument = (char *)malloc(sizeof(char) * (len + 1));
	if (!sorted_argument)
		return (1);
	sorted_argument[len] = '\0';
	i = -1;
	while (++i < len)
		sorted_argument[i] = argv[1][i];
	ft_sort_str(sorted_argument, len);


	current_perm = (char *)malloc(sizeof(char) * (len + 1));
	if (!current_perm)
	{
		free(sorted_argument);
		return (1);
	}
	current_perm[len] = '\0';


	used_flag = (int *)calloc(len, sizeof(len));
	if (!used_flag)
	{
		free(sorted_argument);
		free(current_perm);
		return (1);
	}


	ft_generate_permutation(sorted_argument, current_perm, used_flag, len, 0);


	free(sorted_argument);
	free(current_perm);
	free(used_flag);
	return (0);

}