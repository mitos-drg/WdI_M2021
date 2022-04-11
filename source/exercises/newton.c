#include <stdio.h>

int silnia(int n)
{
    int res = 1;
    for (int i=2; i<=n; ++i)
        res *= i;
    return res;
}
/*int newton(int n, int k)
{
    if (k==0 || k==n)
        return 1;
    return newton(n-1, k-1)+newton(n-1, k);
}*/
int newton(int n, int k)
{
    int pascal[k+1];
    pascal[0] = 1;
    pascal[1] = 1;
    int ptr = 2;
    for (int i=1; i<n; ++i)
    {
        pascal[ptr] = 1;
        for (int j=ptr-1; ptr > 0; --ptr)
            pascal[ptr] += pascal[ptr-1];
        ptr++;
    }
    return pascal[k];
}

int main()
{
    printf("Newton(3,2): %d", newton(3,2));
    return 0;
}
