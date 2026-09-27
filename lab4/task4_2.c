#include <stdio.h>
#include <math.h>

void print_factorial(unsigned n) {
    printf("%u!= ", n);
    for (unsigned i=1;i<n;i++) {
        printf("%u", i);
    }
    printf("%u\n", n);
}
void print_factorial_backwards(unsigned n) {
    printf("%u!=", n);
    for (unsigned i=n;i>1;i--) {
        printf("%u", i);
    }
    printf("1\n");
}
int main() {
    unsigned n;
    printf("enter a value for n: ");
    scanf("%u", &n);
    print_factorial(n);
    print_factorial_backwards(n);
    return 0;
}