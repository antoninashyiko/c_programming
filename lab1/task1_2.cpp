#include <stdio.h>
#include <math.h>

int main()
{
    float a=pow(10, -4);
    double b=24.33E5;
    long double c=M_PI;
    long double d=exp(1);
    double e=sqrt(5);
    double f=log(100);
    printf("%.2f\n", a);
    printf("%.2f\n", b);
    printf("%.2f\n", c);
    printf("%.2f\n", d);
    printf("%.2f\n", e);
    printf("%.2f\n", f);

    return 0;
}