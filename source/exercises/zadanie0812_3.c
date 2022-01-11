#include <stdio.h>

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
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int A[n1], B[n2], C[n3];
    for (int i=0; i<n1; ++i)
        scanf("%d", &A[i]);
    for (int i=0; i<n2; ++i)
        scanf("%d", &B[i]);
    for (int i=0; i<n3; ++i)
        scanf("%d", &C[i]);

    printf("Liczba liczb wystepujacych we wszystkich 3 tablicach: %d\n", policz(n1, A, n2, B, n3, C));

    return 0;
}
