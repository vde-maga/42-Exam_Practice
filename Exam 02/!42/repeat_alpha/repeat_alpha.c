#include <unistd.h>

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

void	repeat_alpha(char *str)
{
	int	i;
	int	repeat;

	i = 0;
	repeat = 1;
	while (str[i])
	{
		if (is_alpha(str[i]))
		{
			if (is_uppercase(str[i]))
				repeat = str[i] - 'A' + 1;
			else if (is_lowercase(str[i]))
				repeat = str[i] - 'a' + 1;
			while (repeat > 0)
			{
				write(1, &str[i], 1);
				repeat--;
			}
			}
		else
			write(1, &str[i], 1);

		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
}
