
#define N 8
#include<iostream>
using namespace std;

void printSolution(int board[N][N])
{
    static  int k = 1;
    int i,j;
    cout<<("%d-\n",k++);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
            if(board[i][j]) cout<<(" Q ");
            else cout<<(" - ");
        cout<<("\n");
    }
    cout<<("\n");
}


int isSafe(int board[N][N], int row, int col)
{
    int i, j;


    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;


    for (i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return 0;


    for (i=row, j=col; j>=0 && i<N; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}


int solveNQUtil(int board[N][N], int col)
{   int i;

    if (col == N )
    {
        printSolution(board);
        return 1;
    }


    for (i = 0; i < N; i++)
    {

        if ( isSafe(board, i, col) )
        {

            board[i][col] = 1;


            solveNQUtil(board, col + 1) ;

            board[i][col] = 0;
        }
    }


    return 0;
}


void solveNQ()
{


 int board[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };


    if (solveNQUtil(board, 0))
    {
        cout<<("Solution does not exist");
        return ;
    }

    return ;
}


int main()
{
    solveNQ();
    return 0;
}
