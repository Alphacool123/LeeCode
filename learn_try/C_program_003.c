#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int *getRandom()
{
    static int r[10];
    int i;

    srand((unsigned)time(NULL));
    for (i = 0; i < 10; ++i)
    {
        r[i] = rand();
        printf("%d\n", r[i]);
    }

    return r;
}

int main()
{
    int *p;
    int i;

    p = getRandom();
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", *p);
        p++;
    }

    return 0;
}