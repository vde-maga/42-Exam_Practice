#include <stdlib.h>
#include <unistd.h>

int ft_popen(const char *file, char *const argv[], char type)
{
    int pid;
    int pfd[2];

    if (!file || !argv || (type != 'r' && type != 'w'))
        return (-1);
    if (pipe(pfd) == -1)
        return (-1);
    pid = fork();
    if (pid == -1)
    {
        close(pfd[0]);
        close(pfd[1]);
        return (-1);
    }
    else if (pid == 0)
    {
        if (type == 'r')
        {
            close(pfd[0]);
            dup2(pfd[1], 1);
            close(pfd[1]);
        }
        else
        {
            close(pfd[1]);
            dup2(pfd[0], 0);
            close(pfd[0]);
        }
        execvp(file, argv);
        exit(1);
    }
    else
    {
        if (type == 'r')
        {
            close(pfd[1]);
            return (pfd[0]);
        }
        else
        {
            close(pfd[0]);
            return (pfd[1]);
        }
    }
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
    int     fd;
    char    buf[1024];
    int     n;

    printf("=== TESTE 1: Ler saída do 'ls' ===\n");
    fd = ft_popen("ls", (char *const []){"ls", "-la", NULL}, 'r');
    if (fd == -1)
    {
        printf("Erro no ft_popen\n");
        return (1);
    }
    while ((n = read(fd, buf, sizeof(buf) - 1)) > 0)
    {
        buf[n] = '\0';
        printf("%s", buf);
    }
    close(fd);

    printf("\n=== TESTE 2: Ler saída do 'echo' ===\n");
    fd = ft_popen("echo", (char *const []){"echo", "Hello from ft_popen!", NULL}, 'r');
    if (fd == -1)
        return (1);
    while ((n = read(fd, buf, sizeof(buf) - 1)) > 0)
    {
        buf[n] = '\0';
        printf("%s", buf);
    }
    close(fd);

    printf("\n=== TESTE 3: Escrever para 'cat' ===\n");
    fd = ft_popen("cat", (char *const []){"cat", ">", "/dev/null", NULL}, 'w');
    if (fd == -1)
        return (1);
    char *msg = "Esta mensagem foi escrita para o cat!\n";
    write(fd, msg, strlen(msg));
    close(fd);
    usleep(100000); // espera o filho processar

    printf("\n=== TESTE 4: Pipeline ls | grep ===\n");
    fd = ft_popen("ls", (char *const []){"ls", NULL}, 'r');
    if (fd == -1)
        return (1);
    dup2(fd, STDIN_FILENO);
    close(fd);
    fd = ft_popen("grep", (char *const []){"grep", ".c", NULL}, 'r');
    if (fd == -1)
        return (1);
    while ((n = read(fd, buf, sizeof(buf) - 1)) > 0)
    {
        buf[n] = '\0';
        printf("%s", buf);
    }
    close(fd);

    printf("\n=== TESTE 5: Parâmetros inválidos ===\n");
    if (ft_popen(NULL, (char *const []){"ls", NULL}, 'r') == -1)
        printf("NULL file: OK (retornou -1)\n");
    if (ft_popen("ls", NULL, 'r') == -1)
        printf("NULL argv: OK (retornou -1)\n");
    if (ft_popen("ls", (char *const []){"ls", NULL}, 'x') == -1)
        printf("type inválido: OK (retornou -1)\n");

    printf("\n=== TESTE 6: Comando inexistente ===\n");
    fd = ft_popen("comando_que_nao_existe", (char *const []){"cmd", NULL}, 'r');
    if (fd != -1)
    {
        n = read(fd, buf, sizeof(buf) - 1);
        if (n <= 0)
            printf("Comando inexistente: OK (sem output)\n");
        close(fd);
    }

    printf("\n=== TODOS OS TESTES CONCLUÍDOS ===\n");
    return (0);
}
*/