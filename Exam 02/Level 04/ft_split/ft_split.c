/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:49:17 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/25 16:11:52 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	ft_words_count(char *str)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && !is_space(str[i]))
				i++;
		}
	}
	return (word);
}

int	ft_word_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_space(str[i]))
		i++;
	return (i);
}

char	*ft_get_word(char *str)
{
	int		i;
	int		word_size; // Quantas letras tem a palavra
	char	*word; // Array a Devolver

	i = 0;
	word_size = ft_word_size(str); // Ir saber quantas letras tem a palavra
	word = (char *)malloc(sizeof(char) * (word_size + 1)); // Colocar o espaco de letras + '\0'
	if (!word)
		return (NULL);
	while (str[i] && !is_space(str[i])) // Enquanto string for verdadeira e uma letra, coloca conteudo em word
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**dest; // O que Entregar
	int		size; // Quantas Palavras Existem na String Original / Quantos Arrays Precisamos Criar
	int		i; // index de dest
	int		j; // index de str

	size = ft_words_count(str); // Saber Numeros de Palavras
	i = 0;
	j = 0;
	dest = (char **)malloc(sizeof(char *) * (size + 1)); // Alocar Numero de Palavras + NUll LEMBRAR DOS ()
	if (!dest)
		return (NULL);
	while (str[j]) // Percorrer a String Original
	{
		if (!is_space(str[j])) // Se for o Comeco de Uma Palavra
		{
			dest[i] = ft_get_word(&str[j]); // Coloca o resto da Palavra, no espaco do primeiro array
			if (!dest[i])
				return (NULL);
			i++;
			j += ft_word_size(&str[j]); // Anda para a Frente, o resto da palavra
		}
		else // Continua a procurar uma palavra
			j++;
	}
	dest[i] = NULL;
	return (dest);
}
/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/