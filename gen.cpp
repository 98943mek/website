#include <stdio.h>
#include <stdlib.h>

int main()
{
    freopen("sort_inp.txt","w",stdout);

    printf("10000000\n");

    int a,b,c;

    for(int i = 0; i < 10000000; i++)
    {
        a = rand() % 1000 + 1;
        b = rand() % 1000 + 1;
        c = rand();

        printf("%d\n",a * b + c);
    }
}
