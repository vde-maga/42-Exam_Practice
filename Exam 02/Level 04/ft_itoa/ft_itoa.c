/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:49:17 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/12 16:11:52 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_digits_count(int nbr)
{
	int	result;

	result = 0;
	if (nbr <= 0)
		result = 1;
	while (nbr)
	{
		nbr = nbr / 10;
		result++;
	}
	return (result);
}

char	*ft_itoa(int nbr)
{
	int		size;
	char	*result;

	size = ft_digits_count(nbr);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * -1;
	}
	else if (nbr == 0)
		result[0] = '0';
	while (nbr)
	{
		result[--size] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (result);
}
/*
Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr);
*/
