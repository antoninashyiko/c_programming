#include <stdio.h>
#include <float.h>

int main() {
    float a=1.0F; // type float
    do {
        a/=2.0F;
    } while (a+1.0F!=1.0F); // %g chooses which is shorter - decimals or e format
    printf("the smallest positive float a such that 1.0+a==1.0 is: %g %g\n", a, FLT_EPSILON); // machine zero
}