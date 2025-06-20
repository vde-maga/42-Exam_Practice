#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

void	str_capitalizer(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_lowercase(str[i]) && (i == 0 || is_space(str[i - 1])))
			str[i] = str[i] - 32;
		else if (is_uppercase(str[i]) && i != 0 && !is_space(str[i - 1]))
			str[i] = str[i] + 32;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	else
		write(1, "\n", 1);
}

/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay,
	this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
		Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/