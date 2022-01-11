#include <stdio.h>

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

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(n, 0, 1);
    return 0;
}
