#include <stdio.h>
#include <math.h>

double area_elips(double x1, double y1, double x2, double y2) {
    double a=sqrt(pow(x1, 2) + pow(y1, 2));
    double b=sqrt(pow(x2, 2) + pow(y2, 2));
    return a*b*M_PI;
}
int main() {
    double x1, y1, x2, y2;
    printf("enter coordinates for a(r1): ");
    scanf("%lf %lf", &x1, &y1);
    printf("enter coordinates for b(r2): ");
    scanf("%lf %lf", &x2, &y2);

    printf("elips space with r1 and r2= %.2lf\n", area_elips(x1, y1, x2, y2));
}