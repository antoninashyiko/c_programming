#include <stdio.h>
double chain(int k, double x) {
    double result=x;
    for (int i=2; i<=k; i++) {
        result*=-1*x*x/(2*i*(2*i+1));
    }
    return result;
}
int main() {
    int n;
    double x;
    do {
        printf("Enter a number n (0 < n < 25): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 25);
    printf("enter x: ");
    scanf("%lf", &x);

    double result=chain(n,x);
    printf("the xk is %lf", result);
}