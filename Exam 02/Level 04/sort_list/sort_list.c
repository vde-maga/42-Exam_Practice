#include "list.h" // não entregar o ficheiro em si

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*first_node;
	int		temp_data;

	first_node = lst;
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
		{
			temp_data = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp_data;
			lst = first_node;
		}
		else
			lst = lst->next;
	}
	lst = first_node;
	return (lst);
}

/*
1. Criamos um node que armazena o comeco da lista
2. Criamos uma variavel para armazenar o valor, na hora da troca
3. Enquanto existir um next na lista
	1. Se a funcao que recebemos, entrega 0, ou seja, que o valor 1 é maior que o 2
		1. Colocamos o valor do node atual, na temp
		2. O node atual, vai receber os dados do proximo node
		3. O proximo node, recebe o valor da temporaria
		4. Por fim, para voltar atras na lista fazemos com que a lista, aponte para o comeco da mesma, com o first_node
		5. Desta forma, sempre que existir um conjunto que nao esteja ordenado, eles sao trocados e voltamos atras para voltar a fazer os checks, ate 100
	2. Se o numero 1 ja e menor que o 2, entao, simplesmente anda para a frente
4. No final, fazemos com que a lista, que esta a apontar para o fim da mesma, aponte para o comeco, com o first_node

*/

/*
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int	ascending(int a, int b)
{
	return (a <= b);
}
*/