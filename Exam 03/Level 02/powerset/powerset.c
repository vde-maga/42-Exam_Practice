#include <stdlib.h>
#include <stdio.h>

void    ft_populate_set(int *set, int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = 2;
    while (i < argc - 2)
    {
        set[i] = atoi(argv[j]);
        i++;
        j++;
    }
}

void    ft_print_solution(int *set, int *used, int len)
{
    int i;
    int flag = 1;
    i = 0;
    while (i < len)
    {
        if (used[i] == 1)
        {
            if (flag == 1)
            {
                fprintf(stdout, "%d", set[i]);
                flag = 0;
            }
            else
                fprintf(stdout, " %d", set[i]);
        }
        i++;
    }
    fprintf(stdout, "\n");
}

void    ft_generate_powersets(int *set, int *used, int original_number, int len, int index, int current_sum)
{
    if (index == len)
    {
        //printf("ola mae");
        if (current_sum == original_number)
        {
          //  printf("ola pai");
          ft_print_solution(set, used, len);
        }
        return;
    }

    /*
        1. Andar uma posicao para a frente, no caso, do Index, como forma que vai comparar todos os valores do array de set, tal como o bubble sort

        5 vs 1 // 5 vs 2 // 5 vs 3
    */
    ft_generate_powersets(set, used, original_number, len, index + 1, current_sum);

    /*
        Depois de todas as versoes feitas, podemos dizer que o index esta usado, logo, o deixamos falso
    */
    used[index] = 1;

    /*
        Todas as iteracoes anteriores, com o index 0 foram validadas, logo, podemos passar para o proximo index.
        Nisto, e necessario incrementar o valor atual da soma, para nao repetir o mesmo set de indexs, o que geraria valores dups
    */
    ft_generate_powersets(set, used, original_number, len, index + 1, current_sum + set[index]);
    /*
        Anulas as posicoes, para o backtracking
    */
    used[index] = 0;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return (1);
    int *used;
    int *set;
    int len;
    int original_number;

    len = argc - 2;
    original_number = atoi(argv[1]);

    set = (int *)malloc(sizeof(int) * len);
    if (!set)
        return (1);
    ft_populate_set(set, argc, argv);
    used = (int *)calloc(len, sizeof(int));
    if (!used)
    {
        free(set);
        return (1);
    }
    ft_generate_powersets(set, used, original_number, len, 0, 0);
    free(used);
    free(set);
    return (0);
}