#include <stdio.h>
#include <string.h>

#define MAX_ROW     21
#define MAX_COL        21
#define DEC_UNIT    5

#define EOS            '\0'

typedef enum { right = 0, down, left, up } Dir;

#define GET_NEXT_POS(x, y, moveTo) \
{ \
    switch(moveTo) \
    { \
    case right: \
        if (x+1 >= col || flag[y][x+1]) { moveTo = down; y++; } \
        else x++; \
        break; \
    case down: \
        if (y+1 >= row || flag[y+1][x]) { moveTo = left; x--; } \
        else y++; \
        break; \
    case left: \
        if (x-1 < 0 || flag[y][x-1]) { moveTo = up; y--; } \
        else x--; \
        break; \
    case up: \
        if (y-1 < 0 || flag[y-1][x]) { moveTo = right; x++; } \
        else y--; \
        break; \
    } \
} \

void makeZero(char array[][MAX_COL], int row, int col)
{
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            array[i][j] = 0;
}

char decoding(char *bin)
{
    int dec = 0, p = 1;
    char ch;
    
    for (int i=DEC_UNIT-1; i>=0; i--) {
        dec += p*(bin[i]-'0');
        p *= 2;
    }

    if (dec == 0)        ch = ' ';
    else if (dec > 26)    ch = EOS;
    else                ch = 'A'+dec-1;

    return ch;
}

int main()
{
    char input[MAX_ROW*MAX_COL+1];
    // binary data 
    char mat[MAX_ROW][MAX_COL];
    // mark present position 
    char flag[MAX_ROW][MAX_COL]; 

    int T;

    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        int row, col;
        char *pIn;

        scanf("%d %d %s", &row, &col, input);
        
        // init binary matrix 
        makeZero(mat, row, col);
        // init flag array 
        makeZero(flag, row, col);

        // copy to the matrix 
        pIn = input;
        for (int j=0; j<row; j++) {
            memcpy(mat[j], pIn, col);
            mat[j][col] = EOS; pIn += col;
        }

        int maxMove = row * col;
        int move = 1, x = 0, y = 0;
        int strId = 0, binId = 0;

        Dir moveTo = right;

        char bin[DEC_UNIT+1], decStr[128];
        // each test case will be ended in this loop 
        while (move <= maxMove)
        {
            flag[y][x] = 1;
            bin[binId] = mat[y][x];

            GET_NEXT_POS(x, y, moveTo)

            if (binId == DEC_UNIT-1) {
                char ch;
                // throw away any partial characters 
                ch = decoding(bin);
                if (ch != EOS) {
                    decStr[strId] = ch;
                    strId++;
                }
                binId = 0;
            } else {
                binId++; 
            }

            move++;
        }

        // throw away any trailing spaces 
        decStr[strId] = '\0';
        
        for (int j=strId-1; j>=0; j--)
        {
            if (decStr[j] == ' ') decStr[j] = EOS;
            else break;
        }
        
        printf("%d %s\n", i+1, decStr);
        strId = 0;
    }
    
    return 0;
}

