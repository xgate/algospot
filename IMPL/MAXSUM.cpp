#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        int maxSum = 0;
        int sumGreedy = 0, sumAny = 0;

        cin >> n;

        for (int i=0; i<n; i++)
        {
            int a;
            cin >> a;

            if (sumGreedy + a >= sumGreedy)
                sumGreedy += a;
            else
                sumGreedy = 0;

            if (sumAny + a >= 0)
                sumAny += a;
            else
                sumAny = 0;

            maxSum = max(maxSum, max(sumGreedy, sumAny));
        }

        cout << maxSum << endl;
    }

    return 0;
}
