#include <stdio.h>
#include <math.h>

double area_heron(double a, double b, double c){
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
double area_heron_coord(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a=hypot(x2-x1,y2-y1);
    double b=hypot(x3-x2,y3-y2);
    double c=hypot(x3-x1,y3-y1);
    return area_heron(a,b,c);
}
int main() {
    printf("%lf should be 6\n ", area_heron(3,4,5));
    printf("%lf should be 14.69\n ", area_heron(5,6,7));
    double x1, y1, x2, y2, x3, y3;
    printf("Enter coordinates of A: \n");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter coordinates of B: \n");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter coordinates of C: \n");
    scanf("%lf %lf", &x3, &y3);
    
    double s=area_heron_coord(x1,y1,x2,y2,x3,y3);
    printf("Area of triangle: %lf\n", s);
}