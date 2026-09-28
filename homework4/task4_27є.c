#include <stdio.h>
#include <math.h>
double pi(double eps) {
    double term=1, sum=0, bracket=0;
    int k=0;
    while (fabs(term)>=eps) {
        bracket=8.0/(8*k+2)+4.0/(8*k+3)+4.0/(8*k+4)-1.0/(8*k+7);
        term=bracket*pow(-1, k)/pow(16, k);
        sum+=term;
        k++;
    }
    return sum;
}
int main() {
    double eps;
    printf("enter eps: ");
    scanf("%lf", &eps);

    printf("pi=%lf with eps=%lf ", pi(eps), eps);
}