#include <iostream>
#include <algorithm>

using namespace std;

int dp[100][100];

int leftUp(int row, int col) 
{
    col--;
    return (col >= 0 ? dp[row-1][col] : 0);
}

int up(int row, int col, int maxRight)
{
    return (col < maxRight ? dp[row-1][col] : 0);
}

int main()
{
    int C;

    cin >> C;
    while(C--)
    {
        int n;

        cin >> n;
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                cin >> dp[i][j];
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=0; j<=i; j++) {
                int num = dp[i][j];
                dp[i][j] = max(leftUp(i, j) + num, up(i, j, i) + num);
            }
        }

        int maxSum = 0;
        for(int i=0; i<n; i++) {
            maxSum = max(maxSum, dp[n-1][i]);
        }

        cout << maxSum << endl;
    }

    return 0;
}
