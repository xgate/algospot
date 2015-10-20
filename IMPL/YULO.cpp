#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_STUD = 40;

int main()
{
    int T;

    cin >> T;
    while(T--) 
    {
        int N;
        cin >> N;
        int nums[MAX_STUD];
        
        for(int i = 0; i < N; i++) {
            cin >> nums[i];
        }

        sort(nums, nums+N);

        int half = N / 2;
        int top = 0;
        for(int i = 0; i < half; i++) {
            top = max(top, nums[i] + nums[N-i-1]);
        }
        if (N & 1) {
            top = max(top, nums[half] * 2);
        }

        printf("%.1f\n", top / 2.0);
    }
    return 0;
}
