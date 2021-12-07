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

int main()
{
    double Wi[] = {1.0, 2.0, 1.0};
    double x = 0.00000000000000001;
    printf("Wielomian W(x) = (x+1)^2; W(%e) = %e\n", x, horner(2, Wi, x));
    return 0;
}