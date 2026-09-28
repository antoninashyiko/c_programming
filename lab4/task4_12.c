#include <stdio.h>
#include <math.h>

double subfactorial(int n) {
    int n1=0;
    double result=0;
    for (int i=1; i<=n; i++) {
        result=i*result+pow(-1,i); // !n=n*!(n-1)+(-1)^n - formula that connects n element with the previous
    }
    return result;
}
int main() {
    int n;
    do {
        printf("Enter a number n (0 < n < 25): ");
        scanf("%d", &n);
    } while (n <= 0 || n >= 25);
    double result=subfactorial(n);
    printf("the result of the sub factorial is %lf", result);
}