//
// Created by mitos on 01.12.2021.
//

#include <stdio.h>

void print(int* tab, int N)
{
    for (int i=0; i<N; ++i)
        printf("%d, ", tab[i]);
    printf("\n");
}

void popraw(int a[], int l, int r)
{
    int j,k,x;
    j=l;
    k=2*j;
    x=a[j];
    while (r>=k)
    {
        if (r>=k+1)
            if (a[k+1]>a[k] )k++;
        if (a[k]>x)
        {
            a[j]=a[k];
            j=k;
            k=2*j;
        }
        else k=r+1;
    }
    a[j]=x;
}

void heap_sort(int a[], int n)
{
    for(int i=n/2; i>0; i--)
        popraw(a, i, n);
    //print(a, n+1);
    int tmp;
    for(int i=n; i>1; i--)
    {
        tmp = a[i];
        a[i] = a[1];
        a[1] = tmp;
        //printf("i: %d, tmp: %d, a[i]: %d, a[1]: %d\n", i, tmp, a[i], a[1]);
        popraw(a, 1, i-1);
        //print(a, n+1);
    }
}

int main()
{
    int tab[] = {0, 12, 16, 8, 32, 48, 12, 8};
    print(tab, 8);
    heap_sort(tab, 7);
    printf("Tablica po posortowaniu:\n");
    print(tab, 8);
    return 0;
}