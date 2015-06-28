#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <cstring>

using namespace std;

int dp[10000];

bool hasOnlyOneNumber(string s) {
    char c = s.at(0);
    for(int i=0; i<s.size(); i++)
        if (c != s.at(i)) return false;

    return true;
}
// 단지 증감분이 1이어야 한다.
bool isMonotonic(string s) {
    int diff = s.at(1) - s.at(0);
    if (diff != 1 && diff != -1)
        return false;
    for(int i=1; i<s.size(); i++)
        if (s.at(i) - s.at(i-1) != diff)
            return false;

    return true;
}

bool isRepeated(string s) {
    char c1 = s.at(0);
    char c2 = s.at(1);
    for(int i=2; i<s.size(); i++)
        if (s.at(i) != s.at(i-2))
            return false;

    return true;
}

bool isArithmeticSequence(string s) {
    int diff = s.at(1) - s.at(0);
    for(int i=1; i<s.size(); i++)
        if (s.at(i) - s.at(i-1) != diff)
            return false;

    return true;
}

int costFn(string target) {
    if (hasOnlyOneNumber(target))       return 1;
    if (isMonotonic(target))            return 2;
    if (isRepeated(target))             return 4;
    if (isArithmeticSequence(target))   return 5;

    return 10;
}

int fn(string str)
{
    int size = str.size();

    for(int i = 3; i <= 5; i++)
        dp[i] = costFn(str.substr(0, i));

    for(int i = 3; i < size; i += 3) {
        for(int j = 3; j <= 5; j++) {
            int n = i + j;
            if (n > size) break;
            for(int k = 3; k <= 5; k++) {
                if (n - k >= 3) {
                    int cost = dp[n-k] + costFn(str.substr(n-k, k));
                    if (dp[n] == 0) {
                        dp[n] = cost;
                    } else {
                        dp[n] = min(cost, dp[n]);
                    }
                }
            }
        }
    }

    return dp[size];
}

int main()
{
    int t;

    cin >> t;
    while(t--) {
        string input;
        cin >> input;
        cout << fn(input) << endl;
        memset(dp, 0, sizeof(dp));
    }

    return 0;
}
