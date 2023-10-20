#include <stdio.h>
#include <stdbool.h>

void printSolution(int board[8][8]) 
{
    int i; int j;
    for (i = 0; i < 8; i++) 
    {
        for (j = 0; j < 8; j++) 
        {
            if (board[i][j] == 1)
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[8][8], int row, int col) 
{
    int i; int j;

    // Check this row on the left side because right side is empty
    for (i = 0; i < col; i++)
        if (board[row][i] == 1)
            return false;

    // Check upper diagonal on the left side because right side is empty
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check lower diagonal on the left side because right side is empty
    for (i = row, j = col; i < 8 && j >= 0; i++, j--)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solve8Queens(int board[8][8], int col) 
{
    if (col >= 8) 
    {
        printSolution(board);
        return true;
    }

    int result = 0;
    int i;
    for (i = 0; i < 8; i++) 
    {
        if (isSafe(board, i, col)) 
        {
            board[i][col] = 1;
            result = solve8Queens(board, col + 1) || result;
            board[i][col] = 0;
        }
    }

    return result;
}

int main() 
{
    int board[8][8]; int i,j;
    for (i = 0; i < 8; i++) 
    {
        for (j = 0; j < 8; j++) 
        {
            board[i][j] = 0;
        }
    }

    solve8Queens(board, 0);

    return 0;
}