#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/*
1. Sempre checkar por last_fd != -1
2. Ordem de Execucao > PIPE, FORK, DUP2, APONTA
*/

int	picoshell(char **cmds[])
{
	int	i;
	int	last_fd;
	int	pfd[2];
	int	pid;

	i = 0;
	last_fd = -1;
	/*PIPE, FORK, DUP2, APONTA*/
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(pfd) == -1)
		{
			if (last_fd != -1)
				close(last_fd);
			return (1);
		}
		pid = fork();
		if (pid == -1)
		{
			if (last_fd != -1)
				close(last_fd);
			if (cmds[i + 1])
			{
				close(pfd[0]);
				close(pfd[1]);
			}
			return (1);
		}
		else if (pid == 0)
		{
			if (last_fd != -1)
			{
				if (dup2(last_fd, 0) == -1)
					exit(1);
				close(last_fd);
			}
			if (cmds[i + 1])
			{
				close(pfd[0]);
				if (dup2(pfd[1], 1) == -1)
					exit(1);
				close(pfd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		if (last_fd != -1)
			close(last_fd);
		if (cmds[i + 1])
		{
			close(pfd[1]);
			last_fd = pfd[0];
		}
		else
			last_fd = -1;
		i++;
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
/*

//# Teste básico do enunciado
//./picoshell /bin/ls "|" /usr/bin/grep picoshell

//# Teste com echo e pipes múltiplos
//./picoshell echo 'squalala' "|" cat "|" sed 's/a/b/g'

//# Teste com um único comando (sem pipes)
//./picoshell echo "hello world"

//# Teste com wc
//./picoshell ls -la "|" wc -l

//# Teste com cat e grep
//./picoshell cat /etc/passwd "|" grep root

//# Teste com 3 pipes
//./picoshell echo "HELLO WORLD" "|" tr 'A-Z' 'a-z' "|" rev "|" cat

#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	char	***cmds;
	int		cmd_count;
	int		i;
	int		j;
	int		k;
	int		arg_count;
	int		ret;

	// Contar número de comandos (separados por "|")
	cmd_count = 1;
	i = 1;
	while (i < argc)
	{
		if (strcmp(argv[i], "|") == 0)
			cmd_count++;
		i++;
	}
	// Alocar array de comandos (+1 para NULL terminal)
	cmds = malloc(sizeof(char **) * (cmd_count + 1));
	if (!cmds)
		return (1);
	// Preencher cmds
	i = 1;
	j = 0;
	while (j < cmd_count)
	{
		// Contar argumentos deste comando
		arg_count = 0;
		k = i;
		while (k < argc && strcmp(argv[k], "|") != 0)
		{
			arg_count++;
			k++;
		}
		// Alocar array de argumentos (+1 para NULL terminal)
		cmds[j] = malloc(sizeof(char *) * (arg_count + 1));
		if (!cmds[j])
			return (1);
		// Copiar argumentos
		k = 0;
		while (k < arg_count)
		{
			cmds[j][k] = argv[i + k];
			k++;
		}
		cmds[j][arg_count] = NULL;
		i += arg_count + 1; // +1 para saltar o "|"
		j++;
	}
	cmds[cmd_count] = NULL;
	// Executar picoshell
	ret = picoshell(cmds);
	// Libertar memória
	j = 0;
	while (j < cmd_count)
	{
		free(cmds[j]);
		j++;
	}
	free(cmds);
	return (ret);
}
*/