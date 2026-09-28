#include <stdio.h>
#include <math.h>
double task_a(int n) {
    double answer=1.0;
    double factorial=1.0;
    for (int i=1; i<=n; i++) {
        factorial*=1.0/i;
        answer=answer*(1+factorial);
    }
    return answer;
}
double task_b(int n) {
    double answer=1.0, fraction=1.0;
    double sign=1;
    for (int i=1; i<=n; i++) {
        fraction=sign*i*i/pow(2, i);
        sign=-1*sign;
        answer=answer*(1+fraction);
    }
    return answer;
}
int main() {
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    printf("task a: %lf\n", task_a(n));
    printf("task b: %lf\n", task_b(n));
}