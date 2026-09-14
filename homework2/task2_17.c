#include <math.h>
#include <stdio.h>

double sigmoid(double x) {
    return pow(1+exp(-x), -1);
}
double sigmoid_derivative(double x) {
    const double h = 1e-5;
    return (sigmoid(x+h)-sigmoid(x-h))/(2*h);
}
int test_sigmoid() {
    if (sigmoid(0)!=0.5) {
        printf("test for sigmoid has failed\n");
        return 1;
    }
    return 0;
}
int derivative_test_sigmoid() {
    if (fabs(sigmoid_derivative(0) - 0.25) > 1e-6) {
        printf("test for sigmoid derivative has failed\n");
        return 1;
    }
    return 0;
}
int main() {
    if (test_sigmoid() == 0 && derivative_test_sigmoid() == 0) {
        printf("All tests passed successfully!\n");
    }
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("the soft sign function is %lf\n", sigmoid(x));
    printf("the derivative function is %lf\n", sigmoid_derivative(x));
}