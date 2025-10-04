#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_print_solution(char *current_perm)
{
	write(1, current_perm, ft_strlen(current_perm));
	write(1, "\n", 1);
}


void	ft_generate_permutations(char *original_str, char *current_perm, int *used, int n, int k)
{

	/* Condição de Vitória/Final da recursão
	* Quando o número da posição que estamos a trabalhar, for igual ao máximo/tamanho do array original, então
	* Significa que já temos uma versão final do current_perm, logo, podemos o escrever no ecrã
	*/
	if (k == n)
	{
		ft_print_solution(current_perm);
		return;
	}

	int	i;

	i = 0;
	/*
	* Percorremos i vezes, até ao final do tamanho do array original
	*/
	while(i < n)
	{
		/* Se na posição atual, a letra ainda não foi usada, então, entramos:
		* Tornamos a posição do current_perm, recebido como argumento da função, a ser igual à posição que percorremos e vimos ser não usada, à string original
		* Exemplo:
		* Na primeira iteração, de ABC, a posição 0 em used, estará 0. Isso significa que o A, ainda não entrou no current_perm
		* Este if statment, ao ver isso, vai fazer com que o A entre no current_perm, este que quando completo, será impresso
		* Depois disso, torna o A, ou melhor, no array de inteiros, a posição 0 deixa de ser livre e se torna usada, ao o colocar 1
		* É chamada a recursao, que fará o mesmo, até colocar o ABC, dentro de current_perm
		* No final da "primeira chamada" o A, volta a libertado, no array de inteiros, para que nas seguintes versões, ele seja colocado, em casos como o CBA ou BAC

		*/
		if (used[i] == 0)
		{
			current_perm[k] = original_str[i];
			used[i] = 1;
			ft_generate_permutations(original_str, current_perm, used, n, k + 1);
			used[i] = 0;
		}
		i++;
	}
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_original_str(char *str, int permutations_size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < permutations_size - 1)
	{
		j = 0;
		while (j < permutations_size - 1)
		{
			if (str[i] > str[j + 1])
				ft_swap(&str[j], &str[j + 1]);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !argv[1][0])
		return (1);

	
	int	permutations_size;
	char	*current_perm;
	char	*original_str;
	int	*used;
	int	i;

	/* Armazenar string original*/
	original_str = argv[1];
	/* Dar sort a string, para que a recursao, passe por todos os casos possiveis*/
	ft_sort_original_str(original_str, permutations_size);
	
	/* Alocar espaço na memória
	* Este array current_perm, sera constantemente atualizado, ao longo da recursao, com as diferentes versoes possiveis
	*/
	permutations_size = ft_strlen(argv[1]);
	current_perm = (char *)malloc(sizeof(char) * (permutations_size + 1));
	if (!current_perm)
	{
		free(current_perm);
		return (1);
	}
	current_perm[permutations_size] = '\0';

	/*Criar array de inteiros, que serve como flag para verificar se, na iteracao atual da recursao, ja foi usada essa letra
	* Primeiro alocamos o espaco na memoria e depois preenchemos com 0
	*/
	used = (int *)malloc(sizeof(int) * permutations_size);
	if (!used)
	{
		free(used);
		free(current_perm);
		return (1);
	}
	i = 0;
	while (i < permutations_size)
	{
		used[i] = 0;
		i++;
	}

	/* Funcao recursiva, onde enviamos
	* - String recebida no argv[1], mas organizada
	* - um array vazio, que será usado para registar uma das várias versões da permutação
	* - o array de inteiros, com a funcao de flag
	* - O tamanho / quantas vezes é para fazer uma recursão
	* - Posicao atual, que vamos armazenar o current_perm. No caso, como é a primeira iteração, passamos a posição 0
	*/
	ft_generate_permutations(original_str, current_perm, used, permutations_size, 0);
	free(current_perm);
	free(used);
	return (0);
}