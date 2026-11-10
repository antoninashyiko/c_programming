#ifndef C2026_2027_RATIONAL_H
#define C2026_2027_RATIONAL_H
typedef struct Rational_ {
    int num; // numerator(чисельник)
    unsigned int den; // denominator(знаменник)
} Rational;

extern void printRational(Rational r);
extern void reduce(Rational* r);
extern bool inputRational(Rational* r);
extern void sum_rational(Rational r1, Rational r2);
extern void multiply_rational(Rational r1, Rational r2);
extern bool compare_rational(Rational r1, Rational r2);

#endif //C2026_2027_RATIONAL_H