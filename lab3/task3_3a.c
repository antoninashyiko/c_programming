#include <stdio.h>

int main() {
    int x, y, z;
    printf("enter three integers\n");
    scanf("%d %d %d", &x, &y, &z);

    printf("you entered: %d, %d, %d\n", x, y, z);
    int d=x*y*z;
    printf("product: %d\n", d);
}