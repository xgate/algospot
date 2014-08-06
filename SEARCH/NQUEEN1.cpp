#include <stdio.h>

#define MAX_ROW 12
#define MAX_COL 12

int board[MAX_ROW][MAX_COL];
int solution = 0;

void printBoard(int board[][MAX_COL], int size)
{
    int i, j;

    for (i=0; i<size; i++)
    {
        for (j=0; j<size; j++)
            printf("%d", board[i][j]);
        printf("\n");
    }
    printf("END\n");
}

int checkUp(int row, int col)
{
    int i, r;

    r = row-1;

    for(i=r; i>=0; i--)
    {
        if (board[i][col] == 1) return 0;
    }
    return 1;
}

int checkUL(int row, int col)
{
    int r, c;

    r = row-1; c = col-1;

    while (1)
    {
        if (r < 0 || c < 0) break;

        if (board[r][c] == 1) return 0;

        r--; c--;
    }

    return 1;
}

int checkUR(int row, int col, int size)
{
    int r, c;

    r = row-1; c = col+1;

    while (1)
    {
        if (r < 0 || c >= size) break;

        if (board[r][c] == 1) return 0;

        r--; c++;
    }

    return 1;
}

void foo(int size, int rowId, int depth)
{
    int i, j;

    // printBoard(board, size); 

    for (i = 0; i < size; i++)
    {
        if (board[rowId][i] == 0)
        {
            if (checkUp(rowId, i) && checkUL(rowId, i) && checkUR(rowId, i, size))
            {
                if (depth == size) {
                    solution++;
                    return;
                }

                board[rowId][i] = 1;
                foo(size, rowId+1, depth+1);
                board[rowId][i] = 0;
            }
        }
    }
}

int main()
{
    int T, N;
    int i, j;
    int board[MAX_ROW][MAX_COL];

    scanf("%d", &T);

    while(T--)
    {
        for (i=0; i<MAX_ROW; i++)
            for (j=0; j<MAX_COL; j++)
                if (board[i][j]) board[i][j] = 0;

        scanf("%d", &N);

        foo(N, 0, 1);
        printf("%d\n", solution);
        solution = 0;
    }
    return 0;
}
