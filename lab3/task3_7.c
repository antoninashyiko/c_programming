#include <math.h>
#include <stdio.h>

void solve_quadratic(double a, double b, double c) {
    if (fabs(a) < 1e-9) {
        if (fabs(b) < 1e-9) {
            if (fabs(c) < 1e-9) {
                printf("infinite solutions\n");
            }
            else {
                printf("no solutions\n");
            }
        }
        else {
            double x=-c/b;
            printf("one solutio x=%lf\n", x);
        }
        return;
    }
    double D=b*b-4*a*c;
    if (fabs(D) < 1e-9) {
        printf("one solutions x=%lf\n", -b/(2*a));
    }
    else if (D<0) {
        printf("no solutions\n");
    }
    else {
        double sqrt_D=sqrt(D);
        double x1=(-b+sqrt_D)/(2*a);
        double x2=(-b-sqrt_D)/(2*a);
        printf("two solutions x1=%lf, x2=%lf\n", x1, x2);
    }
}
void solve_biquadratic(double a, double b, double c) {
    int ans_count=0;
    if (fabs(a) < 1e-9) {
        if (fabs(b) < 1e-9) {
            if (fabs(c) < 1e-9) {
                printf("infinite solutions\n");
            }
            else {
                printf("no solutions\n");
            }
        }
        else {
            double x=-c/b;
            if (x>0) {
                printf("x1=%lf\n", sqrt(x));
                printf("x2=%lf\n", -sqrt(x));
                ans_count+=2;
            }
            else {
                printf("no solutions\n");
            }
        }
        return;
    }
    double D=b*b-4*a*c;
    if (fabs(D) < 1e-9) {
        double x=-b/(2*a);
        if (x>0) {
            printf("x1=%lf\n", sqrt(x));
            printf("x2=%lf\n", -sqrt(x));
        }
        else if (x==0) {
            printf("x=0");
        }
        else {
            printf("no solutions\n");
        }
    }
    else if (D<0) {
        printf("no solutions\n");
    }
    else {
        double sqrt_D=sqrt(D);
        double x1=(-b+sqrt_D)/(2*a);
        double x2=(-b-sqrt_D)/(2*a);
        if (x1>0) {
            printf("x1=%lf\n", sqrt(x1));
            printf("x2=%lf\n", -sqrt(x1));
            ans_count+=2;
        }
        else if (x1 == 0) {
            printf("x1=0\n");
            ans_count += 1;
        }
        if (x2>0) {
            printf("x3=%lf\n", sqrt(x2));
            printf("x4=%lf\n", -sqrt(x2));
            ans_count+=2;
        }
        else if (x2 == 0) {
            printf("x2=0\n");
            ans_count += 1;
        }
        printf("answer count: %d\n", ans_count);
    }
    if (ans_count == 0) {
        printf("no solutions\n");
    } else {
        printf("answer count: %d\n", ans_count);
    }
}
int main() {
    double a1,b1,c1;
    double a2,b2,c2;
    solve_quadratic(1, -3, 2); // two roots x1=2, x2=1
    solve_quadratic(1, 2, 1); // one root x=-1
    printf("enter coefficients for quadratic equation: ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);

    printf("enter coefficients for biquadratic equation: ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    printf("the solution for quadratic is: \n");
    solve_quadratic(a1, b1, c1);

    printf("the solution for biquadratic is: \n");
    solve_biquadratic(a2, b2, c2);
}