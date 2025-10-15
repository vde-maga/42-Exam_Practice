#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
    int	ch;

	while ((ch = fgetc(f)) != EOF && isspace(ch))
	{}
	if (ch != EOF)
		ungetc(ch, f);
	if (ferror(f))
		return (-1);
    return (1);
}

int match_char(FILE *f, char c)
{
    int	ch = fgetc(f);
	if (ch == c)
	return (1);
	if (ch != EOF)
		ungetc(ch, f);
    return (-1);
}

int scan_char(FILE *f, va_list ap)
{
    int	ch = fgetc(f);
	char	*cp = va_arg(ap, char *);

	if (ch == EOF)
		return (-1);
	*cp = (char)ch;
    return (1);
}

int scan_int(FILE *f, va_list ap)
{
    int	ch = fgetc(f);
	int	result = 0;
	int	signal = 1;
	int	*ip = va_arg(ap, int *);
	if (ch == '-' || ch == '+')
	{
		if (ch == '-')
		signal = -1;
	ch = fgetc(f);
	}
	if (!isdigit(ch))
	{
		if (ch != EOF)
			ungetc(ch, f);
		return (-1);
	}
	while (ch != EOF && isdigit(ch))
	{
		result = result * 10 + (ch - '0');
		ch = fgetc(f);
	}
	if (ch != EOF)
		ungetc(ch, f);
	*ip = result * signal;
    return (1);
}

int scan_string(FILE *f, va_list ap)
{
    int	i = 0;
	int	ch = fgetc(f);
	char	*sp = va_arg(ap, char *);

	if (ch == EOF)
		return (-1);
	while ((ch != EOF) && !isspace(ch))
	{
		sp[i++] = (char)ch;
		ch = fgetc(f);
	}
	sp[i] = '\0';
	if (ch != EOF)
		ungetc(ch, f);
    return (1);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case '\0':
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else 
		{
			if (match_char(f, *format) != 1)
				break;
		}
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list	ap;
	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void print_result(const char *desc, int ret) {
    printf("%s → ft_scanf retornou: %d\n", desc, ret);
}

int main(void) {
    int n;
    char ch;
    char s[128];

	// Teste 1: ler um inteiro simples
    printf("Teste 1: Insira um inteiro (ex: 42): ");
    fflush(stdout);
    int r1 = ft_scanf("%d", &n);
    print_result("Leitura de inteiro", r1);
    if (r1 == 1) printf("Valor lido: %d\n", n);

    // Teste 2: ler um caracter (inclui espaço entre entradas)
    printf("\nTeste 2: Insira um caracter (ex: A): ");
    fflush(stdout);
    int r2 = ft_scanf(" %c", &ch); // espaço no formato para consumir espaços em stdin
    print_result("Leitura de caracter", r2);
    if (r2 == 1) printf("Caracter lido: '%c'\n", ch);

    // Teste 3: ler uma string
    printf("\nTeste 3: Insira uma palavra (ex: hello): ");
    fflush(stdout);
    int r3 = ft_scanf("%s", s);
    print_result("Leitura de string", r3);
    if (r3 == 1) printf("String lida: \"%s\"\n", s);

    // Teste 4: combinação %d %c %s numa só linha
    printf("\nTeste 4: Insira: inteiro caracter palavra (ex: 7 x world): ");
    fflush(stdout);
    int a; char b; char cstr[128];
    int r4 = ft_scanf("%d %c %s", &a, &b, cstr);
    print_result("Leitura combinada", r4);
    if (r4 == 3) printf("Valores lidos: %d, '%c', \"%s\"\n", a, b, cstr);

    // Teste 5: falha de formato (tentar ler inteiro mas inserir letra)
    printf("\nTeste 5: Insira uma letra quando se pede inteiro (ex: x): ");
    fflush(stdout);
    int bad;
    int r5 = ft_scanf("%d", &bad);
    print_result("Leitura com erro de formato", r5);
    if (r5 == 1) printf("Valor lido (não esperado): %d\n", bad);
    else printf("Leitura falhou como esperado ou EOF\n");

    printf("\nFim dos testes.\n");
    return 0;
}
*/