#include <stdio.h>
#include <math.h>

double rec_sinus(double x, unsigned n) {
    double y=x;
    for (unsigned i=1; i<=n; i++) {
        y=sin(y);
    }
    return y;
}
int main() {
    double x;
    unsigned n;
    printf("enter the value for x: ");
    scanf("%lf", &x);
    printf("enter a value for n: ");
    scanf("%u", &n);

    double result=rec_sinus(x, n);
    printf("rec_sinus(%lf, %u) = %lf\n", x, n, result);
}