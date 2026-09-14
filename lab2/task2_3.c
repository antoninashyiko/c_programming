#include <stdio.h>
#include <math.h>

double area_heron(double a, double b, double c){
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
    
int main()
{
    double a, b, c;
    printf("Enter a, b, c: ");
    scanf("%lf%lf%lf", &a, &b, &c);

    printf("area is %.3f\n", area_heron(a, b, c));
}