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

void przenies(int co, int skad, int dokad)
{
    printf("Przenies krazek %d z wiezy %d na wieze %d\n", co, skad, dokad);
}

void hanoi(int m, int skad, int dokad)
{
    if (m > 0)
    {
        if (skad == 0 && dokad == 1)
        {
            hanoi(m-1, skad, dokad);
            przenies(m, skad, 3-skad-dokad);
            hanoi(m-1, dokad, skad);
            przenies(m, 3-skad-dokad, dokad);
            hanoi(m-1, skad, dokad);
        }
        else
        {
            hanoi(m-1, skad, 3-skad-dokad);
            przenies(m, skad, dokad);
            hanoi(m-1, 3-skad-dokad, dokad);
        }
    }
}

void divide(int n, int A[n], int* p, int* d)
{
    int ones = 0;
    for (int i = 0; i < n; ++i)
        ones += A[i];
    int diff = n - ones - ones;

    if (diff > 0)
    {
        int i = 0;
        while (diff > -1 && i < n)
        {
            if (A[i] == 0) diff -= 1;
            else diff += 1;
            i++;
        }
        if (i == n)
        {
            *p = *d = 0;
            return;
        }
        *p = i;

        int count = 0;
        do
        {
            if (A[i]) count++;
            else count--;
            i++;
        }while (count != 0 && i < n);
        if (i == n)
        {
            *p = *d = 0;
            return;
        }
        *d = i;
    }
    else
    {
        int i = n-1;
        while (diff < 1 && i > -1)
        {
            if (A[i] == 0) diff -= 1;
            else diff += 1;
            i--;
        }
        if (i == -1)
        {
            *p = *d = 0;
            return;
        }
        *d = i;

        int count = 0;
        do
        {
            if (A[i]) count++;
            else count--;
            i--;
        }while (count != 0 && i > -1);
        if (i == -1)
        {
            *p = *d = 0;
            return;
        }
        *p = i;
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
