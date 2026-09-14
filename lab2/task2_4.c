#include <stdio.h>
#include <math.h>

double func(double x){
    double y3=x*x*x;
    double y9=y3*y3;
    return y9+y3+1;
}

int main()
{
    double x;
    printf("Enter an integer: ");
    scanf("%lf", &x);

    printf("result x^9+x^3+1= %.6f\n", func(x));
}