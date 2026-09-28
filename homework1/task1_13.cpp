#include <stdio.h>
#include <math.h>

int main()
{
    double a;
    printf("enter number: ");
    scanf("%lf", &a);
    double answer=log10(a);
    printf("log10(%.3f)=%.3f", a, answer);
}