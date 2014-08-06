#include <stdio.h>

#define MAX_SIZE    12

int solution = 0;
short int board[MAX_SIZE];

short int pos[MAX_SIZE];
/* 
    Queen position
    map: hex & binary, not use 4bit
    0x0001  (0000) 0000 0000 0001
    0x0002  (0000) 0000 0000 0010
    0x0004  (0000) 0000 0000 0100
    0x0008  (0000) 0000 0000 1000
    0x0010  (0000) 0000 0001 0000
    0x0020  (0000) 0000 0010 0000
    0x0040  (0000) 0000 0100 0000
    0x0080  (0000) 0000 1000 0000
    0x0100  (0000) 0001 0000 0000
    0x0200  (0000) 0010 0000 0000
    0x0400  (0000) 0100 0000 0000
    0x0800  (0000) 1000 0000 0000
*/

int promising(int row, short int qpos)
{
    int shift = 1;

    for (int i=row-1; i>=0; i--)
    {
        short int tmp = 0;

        if (board[i] & qpos) return 0; 

        // this case 
        // 0000 0000 0000 1000 
        // 0000 0000 0000 0100 --> now 
        tmp = qpos << shift;
        if (board[i] & tmp) return 0;
        // this case 
        // 0000 0000 0000 0010 
        // 0000 0000 0000 0100 --> now 
        tmp = qpos >> shift;
        if (board[i] & tmp) return 0;
        shift++;
    }

    return 1;
}

void foo(int row, int depth, int size)
{
    short int next;

    for (int i=0; i<size; i++)
    {
        next = pos[i];
        if (promising(row, next))
        {
            if (depth == size) {
                solution++;
                return;
            }
            board[row] = next;
            foo(row+1, depth+1, size);
            board[row] = 0x0000;
        }
    }
}

int main()
{
    int N, T;

    // make position 
    for (int i=0; i<MAX_SIZE; i++) {
        pos[i] = 0x0001;
        pos[i] <<= i;
    }

    scanf("%d", &T);
    while (T--)
    {
        for (int i=0; i<MAX_SIZE; i++)
            board[i] = 0;

        scanf("%d", &N);
        foo(0, 1, N);
        
        printf("%d\n", solution);
        solution = 0;
    }
    return 0;
}
