#include <ctype.h>
#include <stdio.h>

char	*g_str;

int		ft_parse_expression(void);

void	ft_error(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of file\n");
}

int	ft_check_arguments(char *str)
{
	int		i;
	char	last_char;
	int		parent_diff;

	i = 0;
	parent_diff = 0;
	while (str[i])
	{
		if (str[i] == '(')
			parent_diff++;
		else if (str[i] == ')')
			parent_diff--;
		else if (!isdigit(str[i]) && str[i] != '+' && str[i] != '*')
			return (ft_error(str[i]), 1);
		if (isdigit(str[i]) && isdigit(str[i + 1]))
			return (ft_error(str[i + 1]), 1);
		if (parent_diff < 0)
			return (ft_error(')'), 1);
		last_char = str[i];
		i++;
	}
	if (parent_diff > 0)
		return (ft_error('('), 1);
	if (last_char == '+' || last_char == '*')
		return (ft_error(0), 1);
	return (0);
}

int	ft_parse_factor(void)
{
	int	value;

	value = 0;
	if (isdigit(*g_str))
		return (*g_str++ - '0');
	while (*g_str == '(')
	{
		g_str++;
		value = ft_parse_expression();
		g_str++;
	}
	return (value);
}

int	ft_parse_term(void)
{
	int	result;
	int	next_value;

	result = ft_parse_factor();
	while (*g_str == '*')
	{
		g_str++;
		next_value = ft_parse_factor();
		result = result * next_value;
	}
	return (result);
}

int	ft_parse_expression(void)
{
	int	result;
	int	next_value;

	result = ft_parse_term();
	while (*g_str == '+')
	{
		g_str++;
		next_value = ft_parse_term();
		result = result + next_value;
	}
	return (result);
}

int	main(int argc, char **argv)
{
	int	result;

	if (argc != 2)
		return (1);
	if (ft_check_arguments(argv[1]) == 1)
		return (1);
	g_str = argv[1];
	result = ft_parse_expression();
	printf("%d\n", result);
	return (0);
}
