#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
 
#include <set>
#include <queue>
 
using namespace std;
 
typedef struct {
    double x, y;
} point_t;
 
const int MAX_V = 100;
const double MAX_DIST = 2000.0;
 
int N;
double d[MAX_V][MAX_V];
 
point_t pt[MAX_V];
 
double getDist(point_t p1, point_t p2)
{
    double x = p1.x-p2.x;
    double y = p1.y-p2.y;
 
    return sqrt(x*x+y*y);
}
 
bool check(double dist)
{
    queue<int> q;  // visited nodes.
    set<int> vset; // node collection.
    pair<set<int>::iterator, bool> ret;
 
    q.push(0);
    vset.insert(0);
     
    while(!q.empty())
    {
        int node = q.front(); q.pop();
 
        for(int i = 0; i < N; i++) 
        {
            if (i != node && d[node][i] <= dist) 
            {
                ret = vset.insert(i);
                // new node was inserted.
                if (ret.second == true) {
                    q.push(i);
                }
                // visit all nodes.
                if (vset.size() == N) {
                    return true;
                }
            }
        }
    }
 
    return false;
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
 
        // get distance
        for(int i = 0; i < N; i++) 
        {
            for(int j = i; j < N; j++) 
            {
                double dist = getDist(pt[i], pt[j]);
 
                d[i][j] = dist;
                d[j][i] = dist;
            }
        }
 
        double l = 0, r = MAX_DIST;
        double m, ans = 0.0;
 
        while(r > l+0.0001)
        {
            m = (l+r)/2;
 
            if (check(m)) {
                r = m;
                ans = m;
            } else {
                l = m;
            }
        }
 
        cout << fixed;
        cout.precision(2);
        cout << ans << endl;
    }
    return 0;
}
