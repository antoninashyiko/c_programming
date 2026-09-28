#include <stdio.h>

int main() {
    long long x, y, z;
    printf("enter three integers: ");
    scanf("%lld %lld %lld", &x, &y, &z);

    printf("you entered^ %lld, %lld, %lld\n", x, y, z);

    long long d=x*y*z;
    printf("product = %lld\n", d);
}