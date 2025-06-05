#include <unistd.h>

int	ft_atoi (char *str)
{
	int	result;
	int	i;

	result = 0;
	i = 0;

	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_tab_mult(int number)
{
	int	i;

	i = 1;
	while (i <= 9)
	{
		ft_putnbr(i);
		ft_putstr(" x ");
		ft_putnbr(number);
		ft_putstr(" = ");
		ft_putnbr(number * i);
		ft_putstr("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	int number;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		ft_tab_mult(number);
	}
	else
	{
		write(1, "\n", 1);
	}
}
