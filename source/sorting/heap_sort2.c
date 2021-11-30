#include <stdlib.h>
#include <stdio.h>

void print(int* tab, int N)
{
    for (int i=0; i<N; ++i)
        printf("%d, ", tab[i]);
    printf("\n");
}

void make_heap(int arr[], int begin, int end)
{
    int tmp = arr[begin];
    int w = begin, p2 = 2*w;
    while (p2 < end)
    {
        if (p2+1 < end && arr[p2] < arr[p2+1])
            p2 = p2+1;
        if (arr[p2] < tmp)
        {
            arr[w] = tmp;
            p2 = end;
        }
        else
        {
            arr[w] = arr[p2];
            w = p2;
            p2 = 2*w;
        }
    }
    arr[w] = tmp;
    //printf("Make heap %d - %d\n", begin, end);
    //print(arr, 16);
}

void heap_sort(int* array, int begin, int end)
{
    for (int i = end-2; i>0; i--)
        make_heap(array, i, end);
    //print(array, end-begin);
    for (int i = end-1; i>1; i--)
    {
        int tmp = array[begin];
        array[begin] = array[i];
        array[i] = tmp;
        make_heap(array, begin, i);
    }
}

int main()
{
    int t[] = {0, 12, 3, 14, 4, 16, 1, 5, 32, 24, 18, 9, 10, 10, 8, 7};
    print(t, 16);
    heap_sort(t, 1, 16);
    print(t, 16);
    return 0;
}
