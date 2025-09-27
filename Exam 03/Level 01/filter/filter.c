
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 109

void	ft_filter(char *haystack, char *needle)
{
	int	i;
	int	j;
	int	k;
	int	needle_size;

	i = 0;
	needle_size = strlen(needle);

	/*
	* Percorre haystack
	* Se a primeira ocorrencia de needle, for igual a haystack, entao, compara ate ao fim
		* No caso, comparo i + j, para ter a certeza que sao os valores certos das duas strings
			* abcdefabc // abc
				* 0 + 0 // 0
				* 0 + 1 // 1
				* 0 + 2 // 2
	* No final da comparacao, verifico se e do mesmo tamanho da needle
	* Se for, entao, escreve K vezes o *
		* Incremento tambem o i, com o tamanho da needle, para skippar os chars que nao quero
	* Se nao, apenas escreve normal
	*/
	while (haystack[i])
	{
		j = 0;
		while (needle[j] && (haystack[i + j] == needle[j]))
			j++;
		if (j == needle_size)
		{
			k = 0;
			while (k < needle_size)
			{
				write(1, "*", 1);
				k++;
			}
			i = i + needle_size;
		}
		else
		{
			write(1, &haystack[i], 1);
			i++;
		}
	}

}


int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		perror("Error: Invalid Number of Arguments");
		return (1);
	}

	char	tmp[BUFFER_SIZE];
	char	*dest;
	int	total_bytes_read;
	ssize_t	bytes_read;

	total_bytes_read = 0;
	dest = NULL;

	/*
	* Loop de Leitura
	* Leio por partes/BUFFER_SIZE o conteudo no STDIO
	* Guardando quantos bytes foram lidos, no momento
	*/

	while ((bytes_read = read(0, tmp, BUFFER_SIZE)) > 0)
	{

		/*
		* Com os bytes lidos no momento, eu incremento a uma variavel total, para saber quanto deve ser o tamanho de dest
		* Dest, no caso, esta sempre a ser incrementada, com realloc e sera a variavel final
		*/
		dest = realloc(dest, total_bytes_read + bytes_read + 1);
		if (!dest)
		{
			free(dest);
			perror("Error: realloc");
			return (1);
		}
		/*
		*	transporto tudo o que ficou dentro da temp/buffer, para a dest, com o memmove
		* 	ele ja faz com que dest, aponte para o comeco da mesma, nao preciso me preocupar com isso
		*/
		memmove(dest, tmp, bytes_read);
		/*
		* Incremento o tamanho de bytes lidos, para as multiplas chamadas do while loop
		*/
		total_bytes_read = total_bytes_read + bytes_read;
		/*
		* NULL character sempre no final, para validar a string
		* Nao preciso me preocupar com o nulo se colocar no meio da string, pois memmove da overlap
		*/
		dest[total_bytes_read] = '\0';
	}
	if (bytes_read < 0)
	{
		perror("Error: read");
		free(dest);
		return (1);
	}
	if (!dest)
		return (0);
	ft_filter(dest, argv[1]);
	free(dest);
	return (0);
}