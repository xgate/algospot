#include <iostream>
#include <algorithm>
#include <cstring>
 
using namespace std;
 
typedef struct {
    int e;
    int m;
} DataType;
 
bool sort_func(DataType d1, DataType d2)
{
    return (d1.e > d2.e);
}
 
int main()
{
    int t;
    DataType d[10001];
 
    cin >> t;
 
    while(t--)
    {
        int n;
 
        memset(d, 0x00, sizeof(d));
        cin >> n;
 
        for (int i = 0; i < n; i++) {
            cin >> d[i].m;   
        }
        for (int i = 0; i < n; i++) {
            cin >> d[i].e;
        }
 
        sort(d, d+n, sort_func);
 
        int micTime = 0, fTime;
        int rt = 0, result = 0;
 
        for (int i = 0; i < n; i++)
        {
            micTime += d[i].m;
            fTime = micTime + d[i].e;  
            if (fTime > result) {
                result = fTime;
            }
        }
        cout << result << endl;
    }
    return 0;
}
