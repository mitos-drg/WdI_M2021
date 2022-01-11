#include <stdio.h>

void expression();
void component();
void factor();

char c;

void factor()
{
    if (c == '(')
    {
        c = getchar();
        expression();
    }
    else
    {
        printf("%c", c);
    }
    c = getchar();
}

void component()
{
    factor();
    while (c == '*')
    {
        c = getchar();
        factor();
        printf("*");
    }
}

void expression()
{
    char sign;
    component();
    while (c == '+' || c == '-')
    {
        sign = c;
        c = getchar();
        component();
        printf("%c", sign);
    }
}

int main()
{
    c = getchar();
    expression();
    return 0;
}