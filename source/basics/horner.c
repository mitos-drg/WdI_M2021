#include <stdio.h>

double polymonial(int deg, double W[deg+1], double x)
{
    double xp = 1;
    double w = 0;
    for (int i = 0; i < deg+1; ++i)
    {
        w += xp*W[i];
        xp *= x;
    }
    return w;
}

double horner(int deg, double W[deg+1], double x)
{
    double w = 0;
    for (int i = deg; i > 0; --i)
    {
        w += W[i];
        w *= x;
    }
    return w + W[0];
}

int digits(int input, int out[32], int base)
{
    int i = 0;
    while (input > 0)
    {
        out[i] = input%base;
        input /= base;
        i++;
    }
    return i-1;
}

void digits2(int input, int base)
{
    if (input <= 0)
        return;
    digits2(input/base, base);
    printf("%d", input%base);
}

int main()
{
    double Wi[] = {1.0, 1.0, 1.0};
    double x = 2.0; //0.001;
    //printf("Wielomian W(x) = (x+1)^2; W(%e) = %e\n", x, horner(2, Wi, x));

    int num, base;
    printf("Podaj liczbe: ");
    scanf("%d", &num);
    printf("Podaj baze: ");
    scanf("%d", &base);
    int dig[32];
    int log = digits(num, dig, base);
    for (int i = log; i >= 0; --i)
    {
        printf("%d", dig[i]);
    }
    printf("\n");
    digits2(num, base);
    return 0;
}