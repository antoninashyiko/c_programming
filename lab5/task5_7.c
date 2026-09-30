#include <stdio.h>
#include <math.h>
int sum_of_something(int n) {
    double a1=0, a2=1, b1=1, b2=0;
    int k=3, ak=0, bk=0, s=0;
    for (; k<=n; k++) {
        bk=b2+a2;
        ak=a2/k+a1*bk;
        a1=a2;
        a2=ak;
        b1=b2;
        b2=bk;
        s+=pow(2, k)/(ak+bk);
    }
    return s;
}
int main() {
    printf("%d\n", sum_of_something(10));
}