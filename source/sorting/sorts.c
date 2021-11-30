#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print(int* tab, int N)
{
    for (int i=0; i<N; ++i)
        printf("%d, ", tab[i]);
    printf("\n");
}

void random_fill(int* t, int size)
{
    srand(time(NULL));
    for (int i=0; i<size; ++i)
        t[i] = rand() % 100;
}

/// TODO: Add proper documentation and commentaries, move to other file
void switch_sort(int* tab, int size)
{
    for (int j=0; j<size; ++j)
    {
        int m = 0;
        for (int i=0; i<size-j; ++i)
        {
            if (tab[i] > tab[m])
            {
                m = i;
            }
        }
        int h = tab[size-1-j];
        tab[size-1-j] = tab[m];
        tab[m] = h;
    }
}

/// TODO: Add proper documentation and commentaries, move to other file
void bubble_sort(int* tab, int size)
{
    for (int j=0; j<size; ++j)
    {
        for (int i=1; i<size-j; ++i)
        {
            if (tab[i] < tab[i-1])
            {
                int c = tab[i];
                tab[i] = tab[i-1];
                tab[i-1] = c;
            }
        }
    }
}
void bubble2_sort(int* tab, int size)
{
    int changes = 0;
    for (int j=0; j<size && !changes; ++j)
    {
        changes = 1;
        for (int i=1; i<size-j; ++i)
        {
            if (tab[i] < tab[i-1])
            {
                int c = tab[i];
                tab[i] = tab[i-1];
                tab[i-1] = c;
                changes = 0;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int tablica[n];
    random_fill(tablica, n);
    printf("Tablica: ");
    print(tablica, n);
    bubble2_sort(tablica, n);
    printf("Posortowane: ");
    print(tablica, n);

	return 0;
}
