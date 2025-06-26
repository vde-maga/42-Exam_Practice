#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	ft_total_strings(char *str)
{
	int	i;
	int	count;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_space(str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_space(str[i]))
			i++;
	}
	return (count);
}

int	ft_word_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_space(str[i]))
		i++;
	return (i);
}

char	*ft_word(char *str)
{
	int		len_word;
	int		i;
	char	*word;

	i = 0;
	len_word = ft_word_length(str);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	while (i < len_word)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	*ft_free_memory(char **strings, int i)
{
	while (i-- > 0)
		free(strings[i]);
	free(strings);
	return (NULL);
}

char	**ft_split(char *str)
{
	char	**strings;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	strings = (char **)malloc(sizeof(char *) * (ft_total_strings(str) + 1));
	if (!strings)
		return (NULL);
	while (*str)
	{
		if (!is_space(*str))
		{
			strings[i] = ft_word(str);
			if (strings[i++] == NULL)
				return (ft_free_memory(strings, i));
			str = str + ft_word_length(str);
		}
		if (*str)
			str++;
	}
	strings[i] = NULL;
	return (strings);
}

/*
int	main(void)
{
	char	**words;
	int		i;
	char	*str;
	char	delim;

	i = 0;
	str = "***Eu***GostoMuitoDeGelado***";
	delim = '*';
	words = ft_split(str, delim);
	if (!words)
	{
		printf("Erro na alocação de memória.\n");
		return (1);
	}
	printf("String original:\n\"%s\"\n\n", str);
	printf("Palavras após o split (delimitador '%c'):\n", delim);
	while (words[i])
	{
		printf("Word[%d]: \"%s\"\n", i, words[i]);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
*/

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

char	**ft_split(char *str);
*/