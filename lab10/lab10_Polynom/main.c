#include <stdio.h>

#include "polynom.h"

int main() {
    Polynomial p;
    inputPolynomial(&p);
    printf("your polynomial is \n");
    printPolynomial(p);
    return 0;
}
