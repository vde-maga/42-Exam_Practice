#include <unistd.h>

int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}
void	alpha_mirror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_lowercase(str[i]))
			str[i] = 'z' - str[i] + 'a';
		else if(is_uppercase(str[i]))
			str[i] = 'Z' - str[i] + 'A';
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
}
