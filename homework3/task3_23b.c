#include <stdio.h>
#include <stdlib.h>

double relu(double x) {
    if (x<=0) {
        return 0;
    }
    return x;
}
double derivative_relu(double x) {
    return (x > 0) ? 1.0 : 0.0; // if x>0 return 1 else 0
}
int main() {
    double x;
    printf("enter x: ");
    scanf("%lf", &x);
    printf("relu(x) = %lf\n", relu(x));
    printf("derivative_relu(x) = %lf\n", derivative_relu(x));
}