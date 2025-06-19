/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:03:08 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/16 17:30:26 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


void	rev_wstr(char *str)
{
	int	i;
	int	end_of_word;
	int	first_word_without_space_check;

	i = ft_strlen(str) - 1;
	first_word_without_space_check = 0;

	while (i >= 0)
	{
		while (i >= 0 && is_space(str[i]))
			i--;
		if (i < 0)
			break;
		end_of_word = i;
		while (i >= 0 && !is_space(str[i]))
			i--;
		// Escrever apenas um espaco em branco quando a primeira palavra ja foi escrita
		if (first_word_without_space_check == 1)
			write(1, " ", 1);
		// Escrever i + 1, ou seja, a letra e nao o espaco, o numero de vezes equivalente ao tamanho da palavra
		write(1, &str[i + 1], end_of_word - i);
		// Depois de passado uma vez o loop, ou seja, a primeira palavra escrita, faz com que o if de escrita seja sempre ativo
		first_word_without_space_check = 1;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	write (1, "\n", 1);
}

/*
	1. Comecamos do final da string
	2. Enquanto nao chegamos ao fim da string
		1. Passamos os espacos para a frente
		2. Se o i for menos que 0, ou seja, chegamos ao fim da string, sai do loop
		3. Ao passar os espacos a frente, ja sabemos onde e o fim de uma palavra, logo, end = i;
		4. Percorremos as letras
		5. Escrevemos um espaco, se esta nao for a primeira palavra, para nao devolver "-teste"
		6. Escrevemos o conteudo de i, ate ao final de end
 */

/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat
	-e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>

*/
