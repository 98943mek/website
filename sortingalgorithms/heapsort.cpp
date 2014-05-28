#include <stdio.h>
#include <time.h>
#include <algorithm>
using namespace std;

int inp[10000010];

void heapsort(int n)
{
    int i,c,tmp;

    for(i = 1; i < n; i++)
    {
        c = i;

        while(c != 0)
        {
            if(inp[c] > inp[(c >> 1)])
            {
                tmp = inp[c];
                inp[c] = inp[(c >> 1)];
                inp[(c >> 1)] = tmp;

                c >>= 1;
            } else {
                break;
            }
        }
    }

    for(i = n - 1; i > 0; i--)
    {
        tmp = inp[i];
        inp[i] = inp[0];
        inp[0] = tmp;

        c = 0;

        while(c < i)
        {
            if((c << 1) + 2 < i)
            {
                if(inp[c] < max(inp[(c << 1) + 1],inp[(c << 1) + 2]))
                {
                    if(inp[(c << 1) + 1] > inp[(c << 1) + 2])
                    {
                        tmp = inp[c];
                        inp[c] = inp[(c << 1) + 1];
                        inp[(c << 1) + 1] = tmp;

                        c = (c << 1) + 1;
                    } else {
                        tmp = inp[c];
                        inp[c] = inp[(c << 1) + 2];
                        inp[(c << 1) + 2] = tmp;

                        c = (c << 1) + 2;
                    }
                } else {
                    break;
                }
            } else if((c << 1) + 1 < i) {
                if(inp[c] < inp[(c << 1) + 1])
                {
                    tmp = inp[c];
                    inp[c] = inp[(c << 1) + 1];
                    inp[(c << 1) + 1] = tmp;

                    c = (c << 1) + 1;
                }

                break;
            } else {
                break;
            }
        }
    }
}

int main()
{
    freopen("sort_inp.txt","r",stdin);

    int n,i;
    clock_t start,ends;

    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        scanf("%d",inp + i);
    }

    start = clock();

    heapsort(n);

    ends = clock();

    printf("%lf",(double)(ends - start) / CLOCKS_PER_SEC);
}
