#include <stdio.h>
#include <math.h>

double exp_tailor(double x, unsigned n) {
    double sum=1.0;
    double term=1.0;
    for (unsigned i=0; i<n; i++) {
        term+=x/i;
        sum+=term;
    }
    return sum;
}

int main() {
    double x, y;
    unsigned n;
    printf("enter a value for x: ");
    scanf("%lf", &x);
    printf("enter a value for n: ");
    scanf("%u", &n);

    y=exp_tailor(x,n);
    printf("exp_tailor(%lf, %u)=%lf %lf\n",x, n, y, exp(x));
    return 0;
}