#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print(int* tab, int N)
{
    for (int i=0; i<N; ++i)
        printf("%d, ", tab[i]);
    printf("\n");
}

/// TODO: Add proper documentation and commentaries
void quick_sort(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int m = arr[(l+r)/2];
    int i = l, j = r;
    while (i <= j)
    {
        while (arr[i] < m)
            i++;
        while (arr[j] > m)
            j--;
        if (i <= j)
        {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    quick_sort(arr, l, j);
    quick_sort(arr, i, r);
}

int main()
{
    int t[] = {12, 3, 14, 4, 16, 1};
    print(t, 6);
    quick_sort(t, 0, 5);
    print(t, 6);
    return 0;
}
