#ifndef C2026_2027_POLYNOM_H
#define C2026_2027_POLYNOM_H
#include <stdbool.h>

typedef struct Polynomial {
    int power;
    double *coefficients;
} Polynomial;

extern bool inputPolynomial(Polynomial* p);
extern void printPolynomial(Polynomial p);

#endif //C2026_2027_POLYNOM_H
