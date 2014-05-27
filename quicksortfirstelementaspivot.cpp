#include <stdio.h>
#include <time.h>
#include <algorithm>
using namespace std;

int inp[10000010];

void quicksort_first_element_as_pivot(int s, int e)
{
    if(s >= e)
    {
        return;
    }

    int piv = inp[s],fp = s,lp = e,tmp;

    while(fp < lp)
    {
        while(fp < lp && inp[fp] < piv)
        {
            fp++;
        }

        while(fp < lp && inp[lp] > piv)
        {
            lp--;
        }

        if(fp < lp)
        {
            tmp = inp[fp];
            inp[fp] = inp[lp];
            inp[lp] = tmp;
            fp++;
            lp--;
        }
    }

    if(fp == lp)
    {
        quicksort_first_element_as_pivot(s,fp);
        quicksort_first_element_as_pivot(fp + 1,e);
    } else {
        quicksort_first_element_as_pivot(s,lp);
        quicksort_first_element_as_pivot(fp,e);
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

    quicksort_first_element_as_pivot(0,n - 1);
    //sort(inp,inp + n);

    ends = clock();

    printf("%lf",(double)(ends - start) / CLOCKS_PER_SEC);
}
