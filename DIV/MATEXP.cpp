#include <stdio.h>
#include <string.h>
 
const int MAX_N = 100;
 
int N;
int gmat[MAX_N][MAX_N], ans[MAX_N][MAX_N];
 
void cal(int (*m1)[MAX_N], int (*m2)[MAX_N], int (*out)[MAX_N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            for(int k = 0; k < N; k++)
                out[i][j] += (m1[i][k] * m2[k][j]) % 10007;
 
            out[i][j] %= 10007;
        }
    }
}
 
void solve(int p, int (*out)[MAX_N])
{
    if (p == 1) {
        memcpy(out, gmat, sizeof(gmat));
        return ;
    }
 
    if (p == 2) {
        cal(gmat, gmat, out);
        return ;
    }
 
    int m1[MAX_N][MAX_N];
 
    memset(m1, 0, sizeof(m1));
 
    solve(p/2, m1);
 
    if (p%2) {
        int m2[MAX_N][MAX_N];
        memset(m2, 0, sizeof(m2));
 
        cal(gmat, m1, m2);
        cal(m1, m2, out);
    } else {
        cal(m1, m1, out);
    }
}
 
int main()
{
    int c;
 
    scanf("%d", &c);
 
    while(c--)
    {
        int p;
 
        scanf("%d %d", &N, &p);
 
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                scanf("%d", &gmat[i][j]);
 
        memset(ans, 0, sizeof(ans));
 
        solve(p, ans);
 
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                printf("%d ", ans[i][j]);
 
            printf("\n");
        }
    }
    return 0;
}
