#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 42

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_filter(char *message, const char *find)
{
	int	i;
	int	j;
	int	k;
	int	find_lenght;

	i = 0;
	find_lenght = ft_strlen(find);
	/*
	 * Percorrer a mensagem recebida
	*/
	while (message[i])
	{
		j = 0;
		/*
		 * Verificar se estou num intervalo onde
		 *
		 * a mensagem = o que encontrar
		 *
		 * Se for, incrementa o J
		*/
		while (find[j] && message[i + j] == find[j])
			j++;

		/*
		 * Se o J for do mesmo tamanho do Find, entao significa que houve
		 * correspondencia
		*/
		if (j == find_lenght)
		{
			/*
			 * Com correspondencia, escreve * as vezes necessarias
			 *
			 * +
			 *
			 * no final, incrementa o i, o numero de vezes, para
			 * skippar as letras a omitir
			*/
			k = 0;
			while (k < find_lenght)
			{
				write(1, "*", 1);
				k++;
			}
			i = i + find_lenght;
		}
		/*
		 * Se nao houve correspondencia, entao, escreve normal
		*/
		else
		{
			write(1, &message[i], 1);
			i++;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	// copo que sera usado para encher o balde
	char	temp[BUFFER_SIZE];
	// balde que sera enchido pelo copo e sera entregue para a funcao
	char	*stdio_message;
	// intermedio para nao perder a informacao do balde
	// desta forma, nunca perdemos nada dentro de stdio_message
	char	*buffer;
	// saber quantos copos foram usados para encher o balde, para no final
	// alocar os copos certos
	int	total_reads;
	// check dos bytes lidos, para ver se realmnete foi possivel ler
	ssize_t	bytes;

	total_reads = 0;
	stdio_message = NULL;

	/*
	 * armazena todo o conteudo, dentro de temp, para ser colocado em buffer
	 *
	 * 1. Tenta encher o copo com read
	 * 	1. armazena o conteudo lido no copo
	 * 	2. le BUFFER_SIZE de litros de agua
	 * 2. Guarda os litros lidos em bytes, para ver se vale a pena continuar ou nao o loop
	 * 	1. Se 0, fim do ficheiro
	 * 	2. Se menor que 0, houve erro
	 * 	3. Se maior que 0, entao leu coisas
	*/
	while ((bytes = read(0, temp, BUFFER_SIZE)) > 0)
	{
		/*
		 * Aumenta o tamanho do balde, com base nos litros de agua e
		 * copos que temos
		*/
		buffer = realloc(stdio_message, total_reads + bytes + 1);
		if (!buffer)
		{
			free(stdio_message);
			perror("realloc");
			return (1);
		}
		// Apontar o balde, para o comeco do copo
		stdio_message = buffer;
		// Copiar a agua do copo (temp), para o final do balde (stdio_message)
		memmove(stdio_message + total_reads, temp, bytes);
		// atualizar quantos copos foram usados
		total_reads = total_reads + bytes;
		// null pointer do balde
		stdio_message[total_reads] = '\0';
	}
	// Check de Erros
	if (bytes < 0)
	{
		perror("read");
		free(stdio_message);
		return (1);
	}
	if (!stdio_message)
		return (0);
	ft_filter(stdio_message, argv[1]);
	free(stdio_message);
	return (0);
}
