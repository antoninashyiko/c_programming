#include<stdio.h>

double sum_of_something(double u, double v, int n) {
    double a1=u, b1=v, sum=0, a, b;
    double factorial=1;
    for (int i=1; i<=n; i++) {
        a=2*b1+a1;
        b=2*a1*a1+b1;
        factorial*=1.0/(i+1);
        sum+=a*b/factorial;
        a1=a;
        b1=b;
    }
    return sum;
}
int main() {
    double u, v, n;
    printf("enter u and v: ");
    scanf("%lf%lff", &u, &v);
    printf("enter number of iterations n: ");
    scanf("%lf", &n);

    printf("sum Sn=%lf", sum_of_something(u, v, n));
}