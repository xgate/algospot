#include <stdio.h>
#include <string.h>
#include <algorithm>
 
#define MAX_IN 256
 
using namespace std;
 
bool sortfunc(int i, int j)
{
       return (i > j);    
}
 
void printResult(int k, int kNum, int *arr, int arrLen)
{
       for (int i=0; i<kNum; i++) {
             printf("%d", k);
       }
       for (int i=0; i<arrLen; i++) {
             printf("%d", arr[i]);
       }
       printf("\n");
}
 
int main(int argc, char *argv[])
{
       int T;
 
       scanf("%d", &T);
       while(T--)
       {
             int k;
             char n[MAX_IN];
 
             scanf("%s %d", n, &k);
             // index = input, value = appearance count
             int map[10];
             int maxIn = 0, len = strlen(n);
             int inNum;
 
             memset(map, 0, sizeof(map));
            
             for (int i=0; i<len; i++) {
                    inNum = n[i]-'0';
                    map[inNum]++;
                    if (maxIn < inNum) {
                           maxIn = inNum;
                    }
             }
 
             if (maxIn <= k) {
                    // do descending sort and the result is solution
                    sort(n, n+len, sortfunc); 
                    printf("%s\n", n);
             } else {
                    int bigIdx = 0, smallIdx = 0;
                    int bigArr[MAX_IN], smallArr[MAX_IN];
                    int sMap[10], bMap[10];
 
                    memcpy(sMap, map, sizeof(map));
                    memcpy(bMap, map, sizeof(map));
 
                    memset(bigArr, 0, sizeof(bigArr));
                    memset(smallArr, 0, sizeof(smallArr));
 
                    // make big number (num > k)
                    for (int i=k+1; i<10; i++) {
                           if (map[i] > 0) {
                                 bigArr[bigIdx++] = i;
                                 bMap[i]--;
                                 break;
                           }
                    }
 
                    if (bigIdx > 0)
                    {
                           for (int i=0; i<10; i++) {
                                 if (bMap[i] > 0 && i != k) {
                                        for (int j=0; j<bMap[i]; j++)
                                              bigArr[bigIdx++] = i;
                                 }
                           }
                    }
 
                    // make small number (num < k)
                    for (int i=k-1; i>=0; i--) {
                           if (map[i] > 0) {
                                 smallArr[smallIdx++] = i;
                                 sMap[i]--;
                                 break;
                           }
                    }
 
                    if (smallIdx > 0)
                    {
                           for (int i=9; i>=0; i--) {
                                 if (sMap[i] > 0 && i != k) {
                                        for (int j=0; j<sMap[i]; j++)
                                              smallArr[smallIdx++] = i;
                                 }
                           }
                    }
// find solution
                    if (bigIdx > 0 && smallIdx == 0) {
                           sort(&bigArr[1], bigArr+bigIdx);
                           printResult(k, map[k], bigArr, bigIdx);
                    } else {
                           bool isDecided = false;
                           int  bNum=0, sNum=0, kNum=0;
 
                           for (int i=0; i<bigIdx; i++) {
                                 bNum = bNum*10 + bigArr[i];
                                 sNum = sNum*10 + smallArr[i];
                                 kNum = kNum*10 + k;
 
                                 if ((bNum-kNum) < (kNum-sNum)) {
                                        printResult(k, map[k], bigArr, bigIdx);
                                        isDecided = true;
                                        break;
                                 } else if ((bNum-kNum) > (kNum-sNum)) {
                                        printResult(k, map[k], smallArr, smallIdx);
                                        isDecided = true;
                                        break;
                                 }
                           }
 
                           if (isDecided == false) {
                                 printResult(k, map[k], bigArr, bigIdx);
                           }
                    }
             }
       }
       return 0;
}
 
