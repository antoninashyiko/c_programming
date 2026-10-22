#ifndef C2026_2027_MATRIX_H
#define C2026_2027_MATRIX_H

typedef double** MATRIX;

MATRIX input_matrix(int n);
MATRIX add_matrix(const MATRIX a, MATRIX b, int n1, int n2);
MATRIX multiply_matrix(const MATRIX a, MATRIX b, int n1, int n2);
void print_matrix(const MATRIX a, int n);
void delete_matrix(MATRIX a, int n);

#endif //C2026_2027_MATRIX_H