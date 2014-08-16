#include <stdio.h>
#include <math.h>
 
// a1=9; a2=9*a1; a3=8*a2;
int perm(int n, int r)
{
    if (r==1) return 9;
 
    int an=9, rn=9;
 
    while(r > 1) {
        an *= rn;
        r--; rn--;
    }
    return an;
}
 
int cnt = 0;
 
int getNthNum(int *bit, int nth, int nthOfdec, int depth)
{
    int sum=0;
 
    // last digit
    if (depth > nthOfdec) {
        cnt++;
        return 0;
    }
 
    // 1st: [1-9], remain: [0-9]
    for (int i=(depth==1?1:0); i<10; i++)
    {
        if (!bit[i])
        {
            bit[i] = 1;
            sum = getNthNum(bit, nth, nthOfdec, depth+1);
            if (cnt == nth)
                return sum+i*(int)pow(10, nthOfdec-depth);
            bit[i] = 0;
        }
    }
 
    return 0;
}
 
int main()
{
    int nth;
 
    while (1)
    {
        scanf("%d", &nth);
        if (nth == 0) break;
 
        int sum=0;
        int i;
 
        // part1: find nth-of-dec (10<n<100? 100<n<1000? ...)
        for (i=1; i<10; i++)
        {
            int p = perm(10, i);
 
            if ((sum+p) >= nth) break;
            sum = sum+p;
        }
 
        // part2: get nth number
        if (i==1) {
            sum = nth;
        } else {
            int bit[16]={0,};
 
            cnt = sum;
            sum = getNthNum(bit, nth, i, 1);
        }
 
        printf("%d\n", sum);
    }
    return 0;
}

