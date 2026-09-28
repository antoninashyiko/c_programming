#include <stdio.h>
unsigned long long fib(int n) {
    unsigned long long F0, F1, F;
    F0=1UL;
    F1=1UL;
    for(int k=2; k<=n; k++){
        F=F0+F1;
        F0=F1;
        F1=F;
    }
    return F;
}
int max_fib(double a) {
    int n=2;
    unsigned long long F0, F1, F=0;
    F0=1UL;
    F1=1UL;
    while (F<a){
        F=F0+F1;
        F0=F1;
        F1=F;
        n++;
    }
    return n;
}
void sum_fib() {
    unsigned long long F0, F1, F;
    int sum=0;
    F0=1UL;
    F1=1UL;
    for(sum;sum<=100;){
        F=F0+F1;
        F0=F1;
        F1=F;
        sum+=F;
    }
    printf("%d",sum);
}
int main() {
    int n;
    double a;
    printf("Enter a number n: ");
    scanf("%d",&n);
    printf("enter a number a: ");
    scanf("%lf",&a);

    printf("Fibonacci element n: %ull\n",fib(n));
    printf("Fibonacci max element smaller than a: %lf\n",a);
    printf("sum of element in fibonacci less than 1000");
    sum_fib();
}