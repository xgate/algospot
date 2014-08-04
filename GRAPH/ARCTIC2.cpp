#include <iostream>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
typedef struct {
    double x, y;
} point_t;
 
const int MAX_V = 100;
const double MAX_COST = 2000.0;
 
int N;
double cost[MAX_V][MAX_V];
double mincost[MAX_V];
bool used[MAX_V];
point_t pt[MAX_V];
 
double getDist(point_t p1, point_t p2)
{
    double x = p1.x-p2.x;
    double y = p1.y-p2.y;
 
    return sqrt(x*x+y*y);
}
 
double prim()
{
    for(int i = 0; i < N; i++)
    {
        mincost[i] = MAX_COST;
        used[i] = false;
    }
     
    mincost[0] = 0;
    double ans = 0.0;
 
    while(true)
    {
        int v = -1;
 
        for(int u = 0; u < N; u++) 
        {
            if (!used[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }
 
        if (v == -1) break;
        used[v] = true;
         
        ans = max(mincost[v], ans);
 
        for(int u = 0; u < N; u++) 
        {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
 
    return ans;
}
 
int main()
{
    int C;
 
    cin >> C;
 
    while(C--)
    {
        cin >> N;
 
        for(int i = 0; i < N; i++) {
            cin >> pt[i].x >> pt[i].y;
        }
 
        for(int i = 0; i < N; i++) 
        {
            for(int j = i; j < N; j++) 
            {
                double dist = getDist(pt[i], pt[j]);
 
                cost[i][j] = dist;
                cost[j][i] = dist;
            }
        }
 
        double ans = prim();
 
        cout << fixed;
        cout.precision(2);
        cout << ans << endl;
    }
 
    return 0;
}
