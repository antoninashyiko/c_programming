#include <stdio.h>
#include <math.h>

double chain_sqrt_a(unsigned n) {
    double result=0;
    double x=2;
    for (unsigned i=1; i<=n; i++) {
        result=sqrt(result+x);
    }
    return result;
}
double chain_sqrt_b(unsigned n) {
    double result=0;
    double x=3;
    for (unsigned i=n; i>=1; i--) {
        result=sqrt(result+x*i);
    }
    return result;
}
int main() {
    double y1, y2;
    unsigned n;
    printf("enter a value for n: ");
    scanf("%u", &n);

    y1=chain_sqrt_a(n);
    y2=chain_sqrt_b(n);
    printf("answer for task a: %lf\n", y1);
    printf("answer for task b: %lf\n", y2);
}