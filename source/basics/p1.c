#include <stdio.h>
#include <stdlib.h>

void bubble2_sort(int* tab, int size)
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

void random_fill(int* t, int size, int range)
{
    srand(time(NULL));
    for (int i=0; i<size; ++i)
        t[i] = rand() % range;
}

void fill_matrix(int r, int c, int m[r][c], int range, int step)
{
    int t[c];
    random_fill(t, c, 100);
    bubble2_sort(t, c);

    for (int i=0; i<r; ++i)
    {
        for (int j=0; j<c; ++j)
        {
            //printf("i: %d, j: %d\n", i, j);
            m[i][j] = t[j] + i*step;
        }
    }
}

int check_x(int rows, int cols, int matrix[rows][cols], int x, int* xr, int* xc) //improve it
{
    if (x >= matrix[0][0])
    {
        int pr = 0, pc = 0;
        while (x > matrix[pr][cols-1] && pr < rows)
            pr++;
        while (x > matrix[rows-1][pc] && pc < cols)
            pc++;
        for (int i=0; i<cols; ++i)
        {
            if (matrix[pr][i] == x)
            {
                *xr = pr;
                *xc = i;
                return 1;
            }
        }
        for (int i=0; i<rows; ++i)
        {
            if (matrix[i][pc] == x)
            {
                *xr = i;
                *xc = pc;
                return 1;
            }
        }
    }
    return 0;
}

void print(int R, int C, int tab[R][C])
{
    for (int j=0; j<R; ++j)
    {
        for (int i=0; i<C; ++i)
            printf("%2d, ", tab[j][i]);
        printf("\n");
    }
}

int main()
{
    int rows = 10;
    int cols = 6;
    int x = 42;
    int matrix[rows][cols];

    fill_matrix(rows, cols, matrix, 100, 5);
    print(rows, cols, matrix);
    int xr = -1, xc = -1;
    if(check_x(rows, cols, matrix, x, &xr, &xc))
        printf("Element %d znaleziony na pozycji: \e[33m%d, %d\e[0m\n", x, xr+1, xc+1);
    else printf("\e[31mNie znaleziono %d w macierzy!\e[0m\n", x);
    return 0;
}
