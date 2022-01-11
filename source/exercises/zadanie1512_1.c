#include <stdio.h>

void sum(int n, int A[n], int k)
{
    int i = 0, j = n-1;
    while (i != j)
    {
        if (A[i]+A[j] > k)
            j--;
        else if (A[i]+A[j] < k)
            i++;
        else
        {
            printf("%d = %d+%d\n", k, A[i], A[j]);
            i = j;
        }
    }
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int A[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &A[i]);

    sum(n, A, k);

    return 0;
}
