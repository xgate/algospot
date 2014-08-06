#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COIN    5000
#define MAX_COUNT    1000000007

int compare(const void *a, const void *b)
{
    return ( *(int *)a - *(int *)b );
}

int main()
{
    int T;

    scanf("%d", &T);
    while(T--)
    {
        int cost, coinNum;
        // 입력받은 코인들 
        int coins[MAX_COIN];
        // 정답이 저장될 공간 
        long long coinArr[MAX_COIN+1];

        scanf("%d %d", &cost, &coinNum);

        memset(coinArr, 0, sizeof(coinArr));

        // 입력 
        for (int i = 0; i < coinNum; i++) 
            scanf("%d", &coins[i]);

        //coins 정렬 
        qsort( coins, coinNum, sizeof(int), compare ); 

        // DP 
        for (int i = 0; i < coinNum; i++)
        {
            int coin = coins[i];

            if (coin > cost) break;

            coinArr[coin]++;

            for (int j = 1; coin + j <= cost; j++) 
            {
                if (coinArr[j] >= 0)
                    coinArr[j + coin] += coinArr[j];
            }
        }

        long long cnt = 0;
        cnt = coinArr[cost];

        if ( cnt > MAX_COUNT )
            printf("%d\n", (cnt % MAX_COUNT));
        else
            printf("%d\n", cnt);
    }
    return 0;
}
