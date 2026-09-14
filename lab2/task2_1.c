#include <stdio.h>
#include <math.h>

int main()
{
    double x;
    const double pi=3.14159;
    printf("enter x (deg): ");
    scanf("%lf", &x);

    double xrad=x*(pi/180.0);
    double result=cos(xrad);
    printf("cos= %.6f\n", result);
}