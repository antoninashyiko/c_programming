#include <stdio.h>

double task_a(int n, double b) {
    double sum=b;
    for (int i=1; i<=n; i++) {
        sum=sum+1/sum;
    }
    return sum;
}
double task_b(int n) {
    double b=4*n+2;
    for (int i = n - 1; i >= 0; i--){
        b=4*(n-i)+2+1/b;
    }
    return b;
}
double task_c(int n) {
    double b=0;
    for (int i = n - 1; i >= 0; i--){
        if (i%2==0) {
            b=2+1.0/1;
        }
        else {
            b=1+1.0/2;
        }
    }
    return b;
}
int main() {
    double x=task_a(10, 10);
    double y=task_b(10);
    double z=task_c(10);
    printf("task a=%lf, task b=%lf, task c=%lf\n", x, y, z);
}