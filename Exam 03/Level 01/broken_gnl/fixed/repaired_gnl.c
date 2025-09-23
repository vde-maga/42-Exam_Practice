#include "repaired_gnl.h"

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] && s[i] != c) 
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}                                         
	return (dest);                            
	
}

size_t	ft_strlen(char *s)
{
	if (!s)
		return 0;
	size_t	ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (*s1)
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == src)
		return (dest);
	return (ft_memcpy(dest, src, n));
}

char	*get_next_line(int fd)
{
	/*
	 * b e uma variavel static, ou seja, e sempre preservado em chamadas de funcao
	 * aqui sao armazenados os restos da leitura anterior, que ainda nao foram
	 * colocados dentro do ret
	*/
	static char	b[BUFFER_SIZE + 1] = "";

	/*
	 * ret e a string que sera construida, para ser devolvida
	 * comeca como nula, e sempre que chamada a funcao, ela se torna nula
	 * o buffer, vai sempre, com o passar da funcao, aumentar o quando ela aloca
	 * e o quanto ela tem
	 * desta forma, na ultima chamada, ela tera o conteudo todo guardado nela,
	 * com um unico malloc
	*/
	char	*ret = NULL;

	/*
	 * tmp e onde guardamos o pointer para o \n
	 * fazemos este passo agora, pois, em outras chamadas que nao a primeira,
	 * pode existir o caso de ainda existir um newline, dentro do buffer
	 * exemplo
	 *
	 * ola mundo\n como vais?\n
	*/
	char	*tmp = ft_strchr(b, '\n');
	

	/*
	 * Aqui e onde fazemos a leitura de novos newslines
	 * Enquanto nao encontramos a newline, dentro de tmp
	*/
	while (!tmp)
	{
		/*
		 * Junta o conteudo que o buffer tem, a ret
		 * Na primeira iteracao, b esta vazio, nada e feito
		 * Nas proximas iteracoes, b pode ter uma linha que nao tem \n,
		 * e esse conteudo, mesmo sem newline, precisa ser adicionado a ret,
		 * para que nas proximas iteracoes, a frase seja completada
		 *
		 * 1. ola
		 * 2. ola mundo\n
		 * 
		 * Desta forma, o restante dentro de buffer, antes de encontrar uma nova \n
		 * e adicionado, nao perdendo informacao
		*/
		if (!str_append_str(&ret, b))
			return (NULL);
		/*
		 * Adicionamos conteudo ao buffer
		*/
		int	read_ret = read(fd, b, BUFFER_SIZE);
		/*
		 * check para erros de leitura (-1) + end of file (0)
		 *
		 * Se nada for lido, pelo read, entao, b esta vazio
		*/
		if (read_ret == -1 || read_ret == 0)
		{
			free(ret);
			return (NULL);
		}
		
		/*
		 * Acrescentamos o 0 ao final do buffer, para o deixar uma string valida
		*/ 

		b[read_ret] = 0;

		/*
		 * Procuramos mais uma vez pelo \n
		 * Estamos a avancar o while loop, pois nele, fazemos apenas o acrescentar
		 * de um \n por vez
		*/
		tmp = ft_strchr(b, '\n');
	}
	/*
	 * Agora, depois de sair do while loop, tenho a certeza que tenho uma \n dentro de buffer
	 * tmp esta na posicao do \n / esta a apontar para o \n
	 *
	 * Aqui, adicionamos o conteudo presente no buffer, para dentro do ret
	 * Para tal, fazemos com que o codigo copie o buffer, para dentro de ret, tmp - b + 1
	 * que e o mesmo que dizer que
	 *
	 * vai ao buffer, avanca ate ao \n??
	*/
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	/*
	 * Colocar o que restou de buffer, para a proxima chamada
	 * Desta forma, nenhum \n falha
	*/
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	return (ret);
}
/*
#include <stdio.h>
#include <fcntl.h>
int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		printf("#### NEW LINE ###");
		free(line);
	}
	close(fd);
	return (0);
}
*/
