#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	last_word(char *str)
{
	int	i;
	int	end;
	int	start;
	int	last_word_check;

	i = ft_strlen(str) - 1;
	end = 0;
	start = 0;
	last_word_check = 0;

	while (is_space(str[i]) && last_word_check == 0 && str[i])
		i--;
	end = i;
	while (!is_space(str[i]) && last_word_check == 0 && str[i])
		i--;
	start = i + 1;
	if (str[i] && last_word_check == 0 && str[i])
		last_word_check = 1;
	while (start <= end && last_word_check == 1 && str[i])
	{
		write(1, &str[start], 1);
		start++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
}
