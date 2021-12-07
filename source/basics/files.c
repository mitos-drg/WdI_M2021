#include <stdio.h>
#include <string.h>

int count_chars(FILE* file)
{
    rewind(file);
    int c;
    while (fgetc(file) != EOF)
        c++;
    return c;
}

int count_occurence(FILE* file, char x)
{
    rewind(file);
    int counter = 0;
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if (c == x) counter++;
    }
    return counter;
}

int count_lower(FILE* file)
{
    rewind(file);
    int counter = 0;
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        if ('a' < c && c < 'z') counter++;
    }
    return counter;
}

void longest_line(FILE* file, int *line, int *length)
{
    *line = 0;
    *length = 0;
    rewind(file);
    char linebuff[1024];
    int cl = 0;
    while (fgets(linebuff, 1024, file))
    {
        int tl = strlen(linebuff);
        if (tl > *length)
        {
            *length = tl;
            *line = cl;
        }
        cl++;
    }
}

void number_lines(FILE* file)
{
    FILE *out = fopen("numerated.c", "w");
    rewind(file);
    char linebuff[1024];
    int cl = 0;
    while (fgets(linebuff, 1024, file))
    {
        fprintf(out, "/*%d*/%s", cl+1, linebuff);
        cl++;
    }
    fclose(out);
}

int count_words_starting(FILE* file, char start)
{
    rewind(file);
    int counter = 0;
    char cur, last = ' ';
    while ((cur = fgetc(file)) != EOF)
    {
        if (last == ' ' || last == '\n')
            if (cur == start)
                counter++;
        last = cur;
    }
    return counter;
}

int main()
{
    FILE *f = fopen("../source/sorting/heap.c", "r");
    printf("In file is %d characters (including newlines)\n", count_chars(f));
    int ln = 0, len = 0;
    longest_line(f, &ln, &len);
    printf("Longest line: %d with length of %d chars.\n", ln, len);
    printf("Letter \'a\' has %d occurrences in file.\n", count_occurence(f,'a'));
    printf("In file are %d lower case letters.\n", count_lower(f));
    //number_lines(f);
    printf("There are %d words starting with \'a\'\n", count_words_starting(f, 'a'));
    fclose(f);
    return 0;
}
