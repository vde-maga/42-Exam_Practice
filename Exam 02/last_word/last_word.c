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

/*

Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline.

Example:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>

*/
