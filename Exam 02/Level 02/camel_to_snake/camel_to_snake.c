/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:39:52 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/06 16:48:59 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

void	camel_to_snake(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_uppercase(str[i]))
		{
			write(1, "_", 1);
			str[i] = str[i] + 32;
		}
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		camel_to_snake(argv[1]);
	write(1, "\n", 1);
}
/*

Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$

*/
