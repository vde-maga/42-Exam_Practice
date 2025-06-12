/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:37:18 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/12 16:45:03 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pgcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (pgcd(b, a % b));
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	if ((int) a <= 0 || (int) b <= 0)
		return (0);
	else
		return ((a * b) / pgcd(a, b));
}

/*
Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function who takes two unsigned int as parameters and returns the 
computed LCM of those parameters.

LCM (Lowest Common Multiple) of two non-zero integers is the smallest postive
integer divisible by the both integers.

A LCM can be calculated in two ways:

- You can calculate every multiples of each integers until you have a common
multiple other than 0

- You can use the HCF (Highest Common Factor) of these two integers and 
calculate as follows:

	LCM(x, y) = | x * y | / HCF(x, y)
  
  | x * y | means "Absolute value of the product of x by y"

If at least one integer is null, LCM is equal to 0.

Your function must be prototyped as follows:

  unsigned int    lcm(unsigned int a, unsigned int b);
*/
