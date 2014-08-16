#include <stdio.h>
#include <string.h>

typedef struct Table {
    char *unit;
    float val;
    char *convt;
} Table; 

Table t[4] = {
    {"kg", 2.2046f, "lb"},
    {"lb", 0.4536f, "kg"},
    {"l", 0.2642f, "g"},
    {"g", 3.7854f, "l"}
};

int main()
{
    int T;

    scanf("%d", &T);
    for (int i=0; i<T; i++)
    {
        float input;
        char unit[3];

        scanf("%f %s", &input, unit);

        for (int j=0; j<4; j++) {
            if (!strcmp(unit, t[j].unit)) {
                printf("%d %.4f %s\n", i+1, t[j].val*input, t[j].convt);
                break;
            }
        }
    }
    return 0;
}
