#include <stdio.h>
 
#define MAX_N   100001
 
int main()
{
    int t;
    int array[MAX_N];
 
    scanf("%d", &t);
 
    while (t--)
    {
        int n;
        int max = 0;
        int sumGreedy = 0, sumAny = 0;
 
        scanf("%d", &n);
 
        for (int i=0; i<n; i++)
        {
            scanf("%d", &array[i]);
 
            if (sumGreedy + array[i] >= sumGreedy)
                sumGreedy += array[i];
            else
                sumGreedy = 0;
 
            if (sumAny + array[i] >= 0)
                sumAny += array[i];
            else
                sumAny = 0;
 
            if (sumGreedy > sumAny) {
                if (sumGreedy > max)
                    max = sumGreedy;
            } else {
                if (sumAny > max)
                    max = sumAny;
            }
        }
 
        printf("%d\n", max);
    }
 
    return 0;
}
