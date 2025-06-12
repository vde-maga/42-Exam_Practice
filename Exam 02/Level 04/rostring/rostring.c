/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:44:11 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/12 18:23:08 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char *str)
{
	int	i;
	int	first_word_start;
	int	first_word_end;
	int	has_printed;
	int	j;

	i = 0;
	first_word_start = 0;
	first_word_end = 0;
	has_printed = 0;

	// Detectar Primeira Palavra
	while (str[i] && is_space(str[i]))
		i++;
	first_word_start = i;
	while (str[i] && !is_space(str[i]))
		i++;
	first_word_end = i; 

	// Imprimir as Outras Palavras, com um Espaco entre elas
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i])
		{
			if (has_printed == 1)
				write(1, " ", 1);
			while (str[i] && !is_space(str[i]))
			{
				write(1, &str[i], 1);
				i++;
			}
			has_printed = 1;
		}
	}

	// Imprimir Primeira Palavra
	if (first_word_end > first_word_start)
	{
		if (has_printed == 1)
			write(1, " ", 1);
		j = first_word_start;
		while (j < first_word_end)
		{
			write(1, &str[j], 1);
			j++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc >= 2)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
 * Ele comeca por detectar a posicao da primeira letra da primeira palavra e a ultima letra da primeira palavra. 
 * Com estas detetadas, percorremos o restante da string. 
 * Imprimimos a proxima palavra e depois, escrevemos um espaco em branco. 
 * Fazemos isto, ate chegar ao fim da string. 
 * Depois, passamos ao escrever a primeira palavra. 
 * Comecamos por escrever um espaco em branco e depois, enquanto o numero da primeira letra for menor que da ultima letra, escrevemos essa posicao da primeira letra
 *
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/
