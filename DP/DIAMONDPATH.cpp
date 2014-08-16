#include <stdio.h>
#include <math.h>

#define MAX_ITEM    10000

#define GET_LARGE_VALUE(v, v1, v2) (v + v1 >= v + v2)?(v += v1):(v += v2)
    
int main()
{
    int T;

    scanf("%d", &T);
    while(T--)
    {
        int N;

        scanf("%d", &N);

        int length = 2*N-1;
        int numInput = (int)pow(N, 2);
        int item[MAX_ITEM];

        for (int i=0; i<numInput; i++)
            scanf("%d", &item[i]);

        int index = 1;
        // 첫줄은 skip 
        for (int i=2; i<=length; i++)
        {
            int numCnt;
            // 한 줄에 있는 숫자의 개수 
            if (i <= N)    numCnt = i;
            else        numCnt = 2*N-i;
            
            for (int j=0; j<numCnt; j++, index++)
            {
                int ref = index-numCnt;
                // dia 중간까지 
                if (i <= N) {
                    if (j == 0)                item[index] += item[ref+1];
                    else if (j == numCnt-1)    item[index] += item[ref];
                    else GET_LARGE_VALUE(item[index], item[ref+1], item[ref]);
                }
                // dia 중간이후 
                else
                    GET_LARGE_VALUE(item[index], item[ref-1], item[ref]);
            }
        }

        printf("%d\n", item[numInput-1]);
    }
    return 0;
}
