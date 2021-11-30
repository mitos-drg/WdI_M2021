#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/// TODO: Move to somewhere else, e.g. utils.h
void print(int* tab, int N)
{
    for (int i=0; i<N; ++i)
        printf("%d, ", tab[i]);
    printf("\n");
}

/// TODO: Add proper documentation and commentaries
void merge(int arr[], int l, int m, int r)
{
    int n1 = m-l;
    int n2 = r-m;

    int L[n1], R[n2];

    memcpy(L, &arr[l], n1*sizeof(int));
    memcpy(R, &arr[m], n2*sizeof(int));

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        k++;
        j++;
    }
}

/// TODO: Add proper documentation and commentaries, optional header etc.
void merge_sort(int arr[], int l, int r)
{
    if (l < r-1)
    {
        merge_sort(arr, l, (r+l)/2);
        merge_sort(arr, (r+l)/2, r);
    }
    merge(arr, l, (r+l)/2, r);
}

int main()
{
    int t[] = {12, 3, 14, 4, 16, 1};
    print(t, 6);
    merge_sort(t, 0, 6);
    print(t, 6);
    return 0;
}
