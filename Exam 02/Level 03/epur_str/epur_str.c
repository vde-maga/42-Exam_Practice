#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	epur_str(char *str)
{
	int	i;
	int	is_printed;

	i = 0;
	is_printed = 0;
	while (is_space(str[i]) && is_printed == 0)
		i++;
	while (!is_space(str[i]) && is_printed == 0)
	{
		is_printed = 1;
		write(1, &str[i], 1);
		i++;
	}
	while (str[i])
	{
		while (is_space(str[i]) && is_printed == 1)
			i++;
		if (!is_space(str[i]) && is_printed == 1)
			write(1, " ", 1);
		while (!is_space(str[i]) && is_printed == 1)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
}

/*
 * Assignment name  : epur_str
 * Expected files   : epur_str.c
 * Allowed functions: write

	* --------------------------------------------------------------------------------
 *
 *  Write a program that takes a string,
	and displays this string with exactly one
 *  space between words,
	with no spaces or tabs either at the beginning or the end,
 *  followed by a \n.
 *
 *  A "word" is defined as a part of a string delimited either by spaces/tabs,
	or
 *  by the start/end of the string.
 *
 *  If the number of arguments is not 1, or if there are no words to display,
	the
 *  program displays \n.
 *
 *  Example:
 *
 *  $> ./epur_str "See? It's easy to print the same thing" | cat -e
 *  See? It's easy to print the same thing$

	*  $> ./epur_str " this        time it      will     be    more complex  . " | cat
	-e
 *  this time it will be more complex .$
 *  $> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
 *  $
 *  $> ./epur_str "" | cat -e
 *  $
 *  $>
 *  */
