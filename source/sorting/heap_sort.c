#include <stdlib.h>
#include <stdio.h>

void print(int* tab, int N)
{
    for (int i=0; i<N; ++i)
        printf("%d, ", tab[i]);
    printf("\n");
}

/// TODO: Add proper documentation and commentaries, implement heap sort
void heap_sort(int arr[], int l, int r)
{

}

void correct_heap(int arr[], int l, int r)
{
    int w = l, p2 = 2*w, tmp = arr[w];
}

int main()
{
    int t[] = {12, 3, 14, 4, 16, 1};
    print(t, 6);
    heap_sort(t, 0, 5);
    print(t, 6);
    return 0;
}

