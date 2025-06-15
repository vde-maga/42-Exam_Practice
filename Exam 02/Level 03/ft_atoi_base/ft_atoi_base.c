int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	converted_char_to_int;
	int	i;
	int	signal;

	if (str_base < 2 || str_base > 16)
		return (0);
	result = 0;
	i = 0;
	signal = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = signal * -1;
		i++;
	}
	while (str[i])
	{
		converted_char_to_int = -1;         // valor invalido, para nao dar erro
		if (str[i] >= '0' && str[i] <= '9') // base 10 normal do atoi, que tambem converte bases menores
			converted_char_to_int = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f') // base 16 para cima
			converted_char_to_int = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			converted_char_to_int = str[i] - 'A' + 10;
		else // se nao for um caracter valido, skip
			break ;
		if (converted_char_to_int >= str_base) // se o valor convertido, for invalido, skip
			break ;
		result = result * str_base + converted_char_to_int; // conversao, baseada na base como o *10, mas pode ser *16 ou *2
		i++;
	}
	return (signal * result);
}

/*
#include <stdio.h>

int	main(void)
{
	int	bases[] = {10, 2, 16, 16, 8, 16, 16, 2, 10};
	int	result;

	const char *test_cases[] = {"10",    // Base 10
								"101",   // Base 2
								"1A",    // Base 16
								"-1F",   // Base 16, negativo
								"777",   // Base 8
								"ZZ",   
									// Caso inválido (não reconhecido em bases até 16)
								"   1a", // Espaços no início
								"+100",  // Sinal positivo explícito
								"-100",  // Sinal negativo
								NULL};
	for (int i = 0; test_cases[i] != NULL; i++)
	{
		result = ft_atoi_base(test_cases[i], bases[i]);
		printf("String: \"%s\", Base: %d, Resultado: %d\n", test_cases[i],
			bases[i], result);
	}
	return (0);
}
*/
/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
*/
