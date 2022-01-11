#include <stdio.h>
#include <string.h>

void read_array(int n, int arr[n])
{
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
}
void print(int* tab, int N)
{
    for (int i=0; i<N; ++i)
        printf("%d, ", tab[i]);
    printf("\n");
}

void count_array(int n, int m, int A[n], int B[m])
{
    memset(B, 0, m * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        if (A[i] < 0)
            B[0]++;
        else if (A[i] < m)
            B[A[i]]++;
    }
    for (int i = 1; i < m; ++i)
        B[i] += B[i-1];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int A[n], B[m];
    read_array(n, A);
    count_array(n, m, A, B);
    print(B, m);
}
