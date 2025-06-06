/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:51:43 by vde-maga          #+#    #+#             */
/*   Updated: 2025/06/06 17:00:24 by vde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	do_op(int number1, char operator, int number2)
{
	if (operator == '+')
		printf("%d", number1 + number2);
	else if (operator == '-')
		printf("%d", number1 - number2);
	else if (operator == '*')
		printf("%d", number1 * number2);
	else if (operator == '/')
		printf("%d", number1 / number2);
	else if (operator == '%')
		printf("%d", number1 % number2);
}

int	main(int argc, char **argv)
{
	int	number1;
	int	number2;

	if (argc == 4)
	{
		number1 = atoi(argv[1]);
		number2 = atoi(argv[3]);
		do_op(number1, argv[2][0], number2);
	}
	printf("\n");
}

/*

Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$

*/
