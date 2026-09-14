#include <stdio.h>
#include <math.h>

int main()
{
   double a, b;
   printf("Enter legs a and b of the triangle: ");
   scanf("%lf %lf", &a, &b);
   double c=sqrt(pow(a, 2)+pow(b, 2));
   printf("Hypotenuse is %.2f\n", c);
}