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

int policz(int n1, int A[n1], int n2, int B[n2], int n3, int C[n3])
{
    int a = 0, b = 0, c = 0;
    int licznik = 0;
    while (a < n1 && b < n2 && c < n3)
    {
        if (A[a] > B[b])
            b++;
        else if (B[b] > C[c])
            c++;
        else if (C[c] > A[a])
            a++;
        else
        {
            licznik++;
            a++;
            b++;
            c++;
        }
    }
    return licznik;
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
