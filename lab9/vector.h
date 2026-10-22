#ifndef C2026_2027_VECTOR_H
#define C2026_2027_VECTOR_H

double* input_vector(int n);
double* add_vectors(const double* a, const double* b, int n);
double* subtract_vectors(const double* a, const double* b, int n);
void print_vector(const double* vec, int n);
void delete_vector(double* vec);

#endif //C2026_2027_VECTOR_H