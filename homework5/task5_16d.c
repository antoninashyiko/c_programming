#include <stdio.h>
#include <math.h>

double exp_tailor(double x, double eps) {
    double term=1, y=term;
    int k=1;
    while (fabs(term)>=eps) {
        term=term*x/k;
        y+=term;
        k++;
    }
    return y;
}
int main() {
    double x, eps, y;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    while (eps<=0) {
        printf("Enter the value of eps >0 PLEASE: ");
        scanf("%lf", &eps);
    }
    y = exp_tailor(x, eps);
    printf("exp(x) = %lf %lf\n", y, exp(x));
}