#include <stdio.h>
#include <string.h>

#define MAX_ROW        21
#define MAX_COL        21
#define ENC_UNIT    5

#define EOS        '\0'
#define SP        ' '

typedef enum {right=0, down, left, up} Direct;

void makeSp(char a[][MAX_COL])
{
    for (int i=0; i<MAX_ROW; i++)
        for (int j=0; j<MAX_COL; j++)
            a[i][j]=SP;
}

int encoding(char *bin, char ch)
{
    int dec;

    strcpy(bin, "00000");

    if (ch != SP) { 
        dec = ch-'A'+1; 

        for (int i=ENC_UNIT-1; dec > 0; i--) {
            bin[i] = dec % 2 + '0';
            dec = 2;
        }
    }

    bin[ENC_UNIT] = EOS;

    return 1;
}

void makeOutput(char mat[][MAX_COL], char *output, int row, int col)
{
    char *pOut;

    pOut = output;
    for (int i=0; i<row; i++) {
        memcpy(pOut, mat[i], col);
        pOut += col;
    }
}

void spTozero(char mat[][MAX_COL], int row, int col)
{
    for (int i=0; i<row; i++)
        for (int j=0; j<col; j++)
            if (mat[i][j] == SP) mat[i][j] = '0';
}

int main()
{
    int T;
    char input[128], bin[ENC_UNIT+1];
    char mat[MAX_ROW][MAX_COL];
    char output[MAX_ROW*MAX_COL+1];

    scanf("%d", &T);
    for (int i=0; i<T; i++)
    {
        int row, col;

        memset(input, EOS, sizeof(input));
        memset(output, EOS, sizeof(output));
        makeSp(mat);

        scanf("%d %d", &row, &col);
        fgets(input, sizeof(input), stdin);
        input[strlen(input)-1]=EOS;

        int x = 0, y = 0;
        Direct moveTo=right;

        for (int j=1; input[j]!=EOS; j++)
        {
            // make binary string: "01010" 
            encoding(bin, input[j]);
            // set the matrix 
            for (int k=0; k<ENC_UNIT; k++)
            {
                mat[y][x]=bin[k];
                // get next position 
                switch(moveTo)
                {
                case right:
                    if (x+1 >= col || mat[y][x+1] != SP) { moveTo=down; y++; }
                    else x++;
                    break;
                case down:
                    if (y+1 >= row || mat[y+1][x] != SP) { moveTo=left; x--; }
                    else y++;
                    break;
                case left:
                    if (x-1 < 0 || mat[y][x-1] != SP) { moveTo=up; y--; }
                    else x--;
                    break;
                case up:
                    if (y-1 < 0 || mat[y-1][x] != SP) { moveTo=right; x++; }
                    else y--;
                    break;
                }
            }
        } // end for 

        // make space to zero 
        spTozero(mat, row, col);
        // make output string 
        makeOutput(mat, output, row, col);
        // print output string 
        printf("%d %s\n", i+1, output);
    }

    return 0;
}
