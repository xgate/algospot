#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
 
using namespace std;
 
struct coord { int i, j; };
 
const int MAX_H = 50;
const int MAX_W = 50;
 
char map[MAX_H][MAX_W];
char tmap[MAX_H][MAX_W];
 
coord dir[] = {
    {-1, 0}, // left
    {1, 0},  // right
    {0, -1}, // up
    {0, 1}   // down
};
 
int ans;
int H, W;
char mychar;
// for debugging
void outmap()
{
    for(int i = 0; i < H; i++) 
    {
        for(int j = 0; j < W; j++)
            printf("%c", tmap[i][j]);
        printf("\n");
    }
    printf("\n");
}
 
bool solve(coord from, coord to, int seg)
{
    if (seg >= 3) return false;
 
    if (to.i < 0 || to.i >= H || to.j < 0 || to.j >= W)
        return false;
 
    // find mychar
    if (tmap[to.i][to.j] == mychar) {
        ans++;
        tmap[to.i][to.j] = '*';
        return true;
    }
 
    // hurdle
    if (tmap[to.i][to.j] != '.')
        return false;
 
    // mark
    tmap[to.i][to.j] = '*';
 
    for(int i = 0; i < 4; i++)
    {
        int ni = to.i+dir[i].i;
        int nj = to.j+dir[i].j;
 
        coord next = {ni, nj};
        int nseg = seg;
        // 방향이 바뀌었단다.
        if (from.i != next.i && from.j != next.j) {
            nseg++;
        }
 
        solve(to, next, nseg);
    }
    // erase mark
    tmap[to.i][to.j] = '.';
 
    return false;
}
 
int main()
{
    int T;
 
    scanf("%d", &T);
 
    while(T--)
    {
        scanf("%d %d", &H, &W);
         
        // input
        for(int i = 0; i < H; i++) 
            scanf("%s", map[i]);
 
        ans = 0;
 
        for(int i = 0; i < H; i++)
        {
            for(int j = 0;  j < W; j++)
            {
                if (isalpha(map[i][j])) 
                {
                    coord c = {i, j};
 
                    mychar = map[i][j];
                    // 원래 맵은 사용하지않는다. 맵을 망가뜨릴 것이므로.
                    memcpy(tmap, map, sizeof(map));
                    // 시작위치는 통로로 만듬. 조건검사를 피하기위한 트릭.
                    tmap[i][j] = '.';
                    solve(c, c, 0);
                    // 여기는 이제 못쓰는거야~
                    map[i][j] = '*';
                }
            }
        }
 
        printf("%d\n", ans);
    }
 
    return 0;
}
