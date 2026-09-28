#include <stdio.h>
#include <math.h>
double polynomial(int n, double x) {
    double y=0;
    if (n == 0) {
        y+=1;
    }
    else {
        y+=1;
        for (int i=1; i<=n; i++) {
            y+=pow(x, i);
        }
    }
    return y;
}
int main() {
    double x;
    int n;
    printf("Enter x: ");
    scanf("%lf", &x);
    printf("Enter n: ");
    scanf("%d", &n);

    printf("polynomial result: %.3lf\n", polynomial(n, x));
}