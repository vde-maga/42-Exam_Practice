#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
/*
#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

// Função que será aplicada a cada elemento da lista
void	uppercase(void *data)
{
	char	*str;

	str = (char *)data;
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32; // Converte para maiúscula
		str++;
	}
}

// Função auxiliar para criar um nó da lista
t_list	*create_node(void *data)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

int	main(void)
{
	char	str1[] = "hello";
	char	str2[] = "world";
	char	str3[] = "test";
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	// Criando nós com strings
	node1 = create_node(str1);
	node2 = create_node(str2);
	node3 = create_node(str3);
	if (!node1 || !node2 || !node3)
		return (1); // Erro ao alocar memória
	node1->next = node2;
	node2->next = node3;
	// Aplicando a função uppercase a cada elemento da lista
	ft_list_foreach(node1, &uppercase);
	// Imprimindo os resultados
	printf("%s\n", (char *)node1->data);
	printf("%s\n", (char *)node2->data);
	printf("%s\n", (char *)node3->data);
	// Liberando memória
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/
/*
Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void				ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;
 */
