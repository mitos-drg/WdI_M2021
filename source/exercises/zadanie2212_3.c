#include <stdio.h>

int spattern(int n, char p[n], int len, char T[len])
{
    int ptr = 0;
    int pos = 0;
    int found = 0;
    while (ptr < len-n-1 && !found)
    {
        while (T[ptr] != p[pos] && ptr < len-n-1)
            ptr++;

        while (T[ptr+pos] == p[pos] && pos < n-1)
            pos++;

        if (pos == n-1)
            found = 1;
        else
        {
            pos = 0;
            ptr++;
        }
    }

    return found;
}

unsigned int hash(char *p, int l, int r, int* maxbase)
{
    unsigned int res = 0;
    *maxbase = 1;
    for (int i=l; i<r; ++i)
    {
        res = ((res*26) + (p[i]-'a')) % 12345679;
        *maxbase *= 26;
    }

    return res;
}

// doesn't work
int fpattern(int n, char p[n], FILE* file)
{
    int ptr = 0;
    int pos = 0;
    int found = 0;
    rewind(file);
    while (!feof(file) && !found)
    {
        while (fgetc(file) != p[pos] && !feof(file))
            ptr++;

        while (fgetc(file) == p[pos] && pos < n-1 && !feof(file))
            pos++;

        if (pos == n-1)
            found = 1;
        else
        {
            fseek(file, pos-1, SEEK_CUR);
            pos = 0;
            ptr++;
        }
    }

    return found;
}

int hpattern(int n, char p[n], int len, char T[len])
{
    int maxbase = 1;
    unsigned int patternHash = hash(p, 0, n-1, &maxbase);
    int m = n-1;
    int ptr = 0;
    int found = 0;

    while(!found && ptr < len-m)
    {
        if (patternHash == hash(T, ptr, ptr+m, &maxbase))
        {
            found = 1;
            for (int i=0; i<n-1 && found; ++i)
            {
                if (T[ptr+i] != p[i])
                    found = 0;
            }
            ptr++;
        }
        else
            ptr++;
    }

    return found;
}

int hpattern2(int n, char p[n], int len, char T[len])
{
    int maxbase = 1;
    unsigned int patternHash = hash(p, 0, n-1, &maxbase);
    unsigned int valueHash = hash(T, 0, n-1, &maxbase);
    int m = n-1;
    int ptr = 0;
    int found = 0;

    printf("Entering while, hash: %d\n", patternHash);

    while(!found && ptr < len-m)
    {
        if (patternHash == valueHash)
        {
            printf("Matching hash %d at %d\n", valueHash, ptr);
            found = 1;
            for (int i=0; i<n-1 && found; ++i)
            {
                if (T[ptr+i] != p[i])
                    found = 0;
            }
            ptr++;
        }
        else
        {
            printf("Unmatching hash %d (%d) at %d\n", valueHash, hash(T, ptr, ptr+m, &maxbase), ptr);
            valueHash -= (maxbase * (T[ptr]-'a'));
            valueHash = (valueHash + 12345679) % 12345679;
            valueHash = ((valueHash*26) + (T[ptr+m]-'a')) % 12345679;
            ptr++;
        }
    }

    return found;
}

int main()
{
    char pat[] = "ala";
    char text[] = "kotaalama";
    int t = spattern(4, pat, 10, text);
    printf("Result from string: %d\n", t);
    t = hpattern2(4, pat, 10, text);
    printf("Result from hashing: %d\n", t);
    return 0;
}
