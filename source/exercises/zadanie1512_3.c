#include <stdio.h>

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
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &A[i]);
    int p = 0, d = 0;
    divide(n, A, &p, &d);
    printf("Podzial tablicy: 0 < %d < %d < n\n", p, d);
    return 0;
}
