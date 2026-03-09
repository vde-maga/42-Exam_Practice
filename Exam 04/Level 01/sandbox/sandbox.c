
/*
1. Exercicio de uso das manpages. As mais importantes sao
	- man 7 signal (nomes dos sinais)
	- man 2 waitpid (macro do errno, funcao waitpid)
	- man sigaction (funcao sigaction)
Enunciado diz as funcoes todas, mas nao diz as macros, logo,
	e para as procurar nas mans
2. Abriste uma man? Coloca o include dela!
	- stdbool do enunciado!
3. Chama os status de wstatus, para facilitar o copy/cola
*/

#include <errno.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void	ft_handle_signal(int sig)
{
	(void)sig;
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	int					pid;
	int					wstatus;
	struct sigaction	sa;

	/*
	1. Configurar signal handling
	2. Fork
	3. Alarm a funcionar
	4. Waitpid - Se for erro, parar processo! (errno e macro)
	5. Handle dos codigos de saidas
	*/
	sa.sa_handler = ft_handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGALRM, &sa, NULL);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		f();
		exit(0);
	}
	alarm(timeout);
	if (waitpid(pid, &wstatus, 0) == -1)
	{
		alarm(0);
		if (errno == EINTR)
		{
			kill(pid, SIGKILL);
			waitpid(pid, NULL, 0);
			if (verbose)
				printf("Bad function: timed out after %u seconds\n", timeout);
			return (0);
		}
		return (-1);
	}
	alarm(0);
	if (WIFEXITED(wstatus))
	{
		if (WEXITSTATUS(wstatus) == 0)
		{
			if (verbose)
				printf("Nice function!\n");
			return (1);
		}
		else
		{
			if (verbose)
				printf("Bad function: exited with code %d\n",
					WEXITSTATUS(wstatus));
			return (0);
		}
	}
	if (WIFSIGNALED(wstatus))
	{
		if (verbose)
			printf("Bad function: %s\n", strsignal(WTERMSIG(wstatus)));
		return (0);
	}
	return (-1);
}