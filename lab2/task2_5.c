#include <stdio.h>
#include <math.h>
#include <stdbool.h>

double Rosenbrock2d(double x, double y) {
    return 100*pow(x*x-y, 2)+pow(x-1, 2);
}
bool iszero(double x) {
    return fabs(x) < 1e-9;
}
int test_Rosenbrock2d() {
    if (!iszero(Rosenbrock2d(1,1))) {
        printf("test_Rosenbrock2d() for (1, 1) failed\n");
        return 1;
    }
    if (!iszero(Rosenbrock2d(-1,1)-4.0)) {
        printf("test_Rosenbrock2d() for (-1, 1) failed\n");
        return 1;
    }
    if (!iszero(Rosenbrock2d(-1,-1)-404.0)) {
        printf("test_Rosenbrock2d() for (1, 1) failed\n");
        return 1;
    }
    return 0;
}
int main() {
    if (test_Rosenbrock2d()==0) {
        printf("tests for Rosenbrock2d() have succeeded\n");
    }
    double x, y;
    printf("input x and y: ");
    scanf("%lf %lf", &x, &y);
    printf("Rosenbrock2d(%lf,%lf) = %lf\n", x, y, Rosenbrock2d(x, y));
}