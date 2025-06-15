/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:26:41 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/06 17:33:08 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // necessario para o size_t

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	const char	*str1 = "hello, world!";
	const char	*reject1 = "aeiou";
	const char	*reject2 = "xyz";
	const char	*reject3 = "!";

	printf("Teste 1 (vogais) -> %zu\n", ft_strcspn(str1, reject1));            
		// Deve retornar 1 ('e')
	printf("Teste 2 (letras ausentes) -> %zu\n", ft_strcspn(str1, reject2));   
		// Deve retornar 13 (nenhuma encontrada)
	printf("Teste 3 (caractere especial) -> %zu\n", ft_strcspn(str1, reject3));
		// Deve retornar 12 ('!')
	return (0);
}
*/
/*

Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject);

*/
