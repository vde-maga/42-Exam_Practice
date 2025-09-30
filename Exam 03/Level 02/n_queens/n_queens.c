#include <stdio.h>
#include <stdlib.h>

void    ft_print_solution(int *board, int number_of_queens)
{
    int i;

    i = 0;
    while (i < number_of_queens)
    {
        fprintf(stdout, "%d", board[i]);
        if (i < number_of_queens - 1)
            fprintf(stdout, " ");
        i++;
    }
    fprintf(stdout, "\n");
}

int ft_abs(int nbr)
{
    if (nbr < 0)
    {
        nbr = nbr * -1;
        return (nbr);
    }
    else
        return (nbr);
}

int ft_is_safe(int *board, int coluna, int linha)
{
    int i;

    i = 0;
    while (i < coluna)
    {
        if (board[i] == linha)
            return (0);
        if (ft_abs(board[i] - linha) == ft_abs(coluna - i))
            return (0);
        i++;
    }
    return (1);
}

void    ft_solve(int *board, int number_of_queens, int coluna)
{
    if (number_of_queens == coluna)
    {
        ft_print_solution(board, number_of_queens);
        return;
    }
    int linha;

    linha = 0;
    while (linha < number_of_queens)
    {
        if (ft_is_safe(board, coluna, linha))
        {
            board[coluna] = linha;
            ft_solve(board, number_of_queens, coluna + 1);
        }
        linha++;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stdout, "Error, Mitada nao tens args");
        return (1);
    }
    int *board;
    int number_of_queens;

    number_of_queens = atoi(argv[1]);
    board = (int *)malloc(sizeof(int) * number_of_queens);
    if (!board)
        return(1);
    ft_solve(board, number_of_queens, 0);
}