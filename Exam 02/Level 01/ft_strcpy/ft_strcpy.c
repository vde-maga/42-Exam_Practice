/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:12:54 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/06 15:21:32 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "00000";
	char	s2[] = "11111";

	printf("Arrays antes da Funcao\n");
	printf("%s\n", s1);
	printf("%s\n", s2);
	printf("Arrays depois da Funcao\n");
	ft_strcpy(s1, s2);
	printf("%s\n", s1);
	printf("%s\n", s2);
}
*/
/*

Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcpy (man strcpy).

Your function must be declared as follows:

char    *ft_strcpy(char *s1, char *s2);

*/
