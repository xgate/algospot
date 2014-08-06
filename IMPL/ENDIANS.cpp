#include <stdio.h>

int main()
{
    int T;
    unsigned int input, result;
    char *pIn, *pRes;

    scanf("%d", &T);

    while(T--)
    {
        scanf("%u", &input);

        pIn = (char *)&input;
        pRes = (char *)&result;

        pIn += 3;
        for(int i=0; i<4; i++)
            *(pRes++) = *(pIn--);

        printf("%u\n", result);
    }
    return 0;
}
