#include <stdio.h>
#include <string.h>

/**
 * Implementation of the sieve of Eratostenes
 * char* out - preallocated character array of size n
 */
void sieve(char* out, int n)
{
    memset(out, 1, n);
    for (int i=2; i*i < n; ++i)
    {
        if (out[i])
        {
            for (int j=i*i; j<n; j += i)
                out[j] = 0;
        }
    }
}

int main()
{
    FILE *f;
    char sito[100];
    sieve(sito, 100);
    
    f = fopen("pierwsze.txt", "w");
    int c = 0;
    for (int i=0; i<100; ++i)
    {
        if (sito[i])
        {
            c++;
            fprintf(f,"%d, ", i);
            if (c%10 == 0) fprintf(f, "\n");
        }
    }
    fclose(f);
        
    return 0;
}
