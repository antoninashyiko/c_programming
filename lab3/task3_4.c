#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int16_t mult(int8_t a, int8_t b) {
    return (int16_t)(a*b);
}

int main() {
    uint64_t x, y, z;
    printf("enter three integers: ");
    scanf("%" SCNu64 ",%" SCNu64 ",%" SCNu64 "", &x, &y, &z);
    printf("you entered: %" PRIu64 ",%" PRIu64 ",%" PRIu64 "\n", x, y, z);

    uint64_t d=x*y*z;
    printf("Product: %" PRIu64 "\n", d);

    uint8_t a, b;
    printf("enter two integers: ");
    scanf("%" SCNu8 ",%" SCNu8 "", &a, &b);
    printf("you entered: %" PRIu8 ",%" PRIu8 "\n", a, b);
    int16_t result=mult(x, y);
    printf("product: %" PRId16 "\n", result);
}