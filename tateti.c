#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h> /* assert() */

#define CELL_MAX (3 * 3 - 1)
#define MAX (CELL_MAX + 1) / 3

char verificar_horizontal(char board[3][3], int i, int j, char c1, char c2, char c3, char winner)
{
    while (i < 3)
    {
        while (j < 3)
        {
            if (board[i][j] != '-')
            {
                if (c1 == '1')
                {
                    c1 = board[i][j];
                }
                else if (c2 == '2')
                {
                    c2 = board[i][j];
                }
                else if (c3 == '3')
                {
                    c3 = board[i][j];
                }
            }
            j++;

            if ((c1 == c2) && (c1 == c3))
            {
                winner = c1;
            }
        }
        c1 = '1';
        c2 = '2';
        c3 = '3';
        j = 0;
        i++;
    }

    return winner;
}

char verificar_vertical(char board[3][3], int i, int j, char c1, char c2, char c3, char winner)
{
    while (j < 3)
    {
        while (i < 3)
        {
            if (board[i][j] != '-')
            {
                if (c1 == '1')
                {
                    c1 = board[i][j];
                }
                else if (c2 == '2')
                {
                    c2 = board[i][j];
                }
                else if (c3 == '3')
                {
                    c3 = board[i][j];
                }
            }
            i++;

            if ((c1 == c2) && (c1 == c3))
            {
                winner = c1;
            }
        }
        c1 = '1';
        c2 = '2';
        c3 = '3';
        i = 0;
        j++;
    }
    return winner;
}

char verificar_diagonal(char board[3][3], int i, int j, char c1, char c2, char c3, char winner)
{
    while (i < 3)
    { // Verificacion diagonal principal
        while (j < 3)
        {
            if (board[i][j] != '-')
            {

                if (i == j)
                {
                    if (c1 == '1')
                    {
                        c1 = board[i][j];
                    }
                    else if (c2 == '2')
                    {
                        c2 = board[i][j];
                    }
                    else if (c3 == '3')
                    {
                        c3 = board[i][j];
                    }
                }
                if ((c2 == c1) && (c2 == c3))
                {
                    winner = c2;
                }
            }
            j++;
        }
        j = 0;
        i++;
    }
        i = 0;
        j = 0;
        c1 = '1';
        c3 = '3';

    while (i < 3)
    { // Verificacion diagonal contraria
        while (j < 3)
        {
            if (board[i][j] != '-')
            {
                if (i == (MAX - 1) && j == 0 || i == 0 && j == (MAX - 1))
                {
                    if (c1 == '1')
                    {
                        c1 = board[i][j];
                    }
                    else if (c2 == '2')
                    {
                        c2 = board[i][j];
                    }
                    else if (c3 == '3')
                    {
                        c3 = board[i][j];
                    }
                }
            }
            j++;
        }
        j = 0;
        i++;
    }
    if ((c2 == c1) && (c2 == c3))
    {
        winner = c2;
    }
    return winner;

}

            void print_sep(int length)
            {
                printf("\t ");
                for (int i = 0; i < length; i++)
                    printf("................");
                printf("\n");
            }

            void print_board(char board[3][3])
            {
                int cell = 0;

                print_sep(3);
                for (int row = 0; row < 3; ++row)
                {
                    for (int column = 0; column < 3; ++column)
                    {
                        printf("\t | %d: %c ", cell, board[row][column]);
                        ++cell;
                    }
                    printf("\t | \n");
                    print_sep(3);
                }
            }

            char get_winner(char board[3][3])
            {
                char winner = '-';
                int i;
                int j;
                char c1;
                char c2;
                char c3;
                c1 = '1';
                c2 = '2';
                c3 = '3';
                i = 0;
                j = 0;
                if (winner == '-')
                {
                    winner = verificar_horizontal(board, i, j, c1, c2, c3, winner);
                }
                if (winner == '-')
                {
                    winner = verificar_vertical(board, i, j, c1, c2, c3, winner);
                }
                if (winner == '-')
                {
                    winner = verificar_diagonal(board, i, j, c1, c2, c3, winner);
                }
                return winner;
            }

            bool has_free_cell(char board[3][3])
            {
                bool free_cell = false;
                int i;
                int j;
                i = 0;
                j = 0;

                while (i <= 3)
                {
                    while (j <= 3)
                    {
                        if (board[i][j] == '-')
                        {
                            free_cell = true;
                        }
                        j++;
                    }
                    j = 0;
                    i++;
                }

                return free_cell;
            }

            int main(void)
            {
                printf("TicTacToe [InCoMpLeTo :'(]\n");

                char board[3][3] = {
                    {'-', '-', '-'},
                    {'-', '-', '-'},
                    {'-', '-', '-'}};

                char turn = 'X';
                char winner = '-';
                int cell = 0;
                while (winner == '-' && has_free_cell(board))
                {
                    print_board(board);
                    printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
                           CELL_MAX);
                    int scanf_result = scanf("%d", &cell);
                    if (scanf_result <= 0)
                    {
                        printf("Error al leer un número desde teclado\n");
                        exit(EXIT_FAILURE);
                    }
                    if (cell >= 0 && cell <= CELL_MAX)
                    {
                        int row = cell / 3;
                        int colum = cell % 3;
                        if (board[row][colum] == '-')
                        {
                            board[row][colum] = turn;
                            turn = turn == 'X' ? 'O' : 'X';
                            winner = get_winner(board);
                        }
                        else
                        {
                            printf("\nCelda ocupada!\n");
                        }
                    }
                    else
                    {
                        printf("\nCelda inválida!\n");
                    }
                }
                print_board(board);
                if (winner == '-')
                {
                    printf("Empate!\n");
                }
                else
                {
                    printf("Ganó %c\n", winner);
                }
                return 0;
            }
