/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 17:28:06 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/12 17:31:16 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	fprime(int number)
{
	long	nbr;
	int		i;

	nbr = number;
	i = 2;
	if (nbr == 1)
	{
		printf("1");
		return ;
	}
	while (number >= i)
	{
		if (number % i == 0)
		{
			printf("%d", i);
			if (number != i)
				printf("*");
			number = number / i;
			i = 2;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	number;

	if (argc == 2)
	{
		number = atoi(argv[1]);
		fprime(number);
	}
	printf("\n");
}

/*
Assignment name  : fprime
Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------

Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid.

Examples:

$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
$

*/
