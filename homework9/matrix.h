#ifndef C2026_2027_MATRIX_H
#define C2026_2027_MATRIX_H

typedef double** MATRIX;

MATRIX input_matrix(int n, int m);
MATRIX add_row_matrix(const MATRIX mat, int n, int m);
MATRIX multiply_matrix(const MATRIX mat1, MATRIX mat2, int n1, int m1, int n2, int m2);
void print_matrix(const MATRIX a, int n, int m);
void delete_matrix(MATRIX a, int n);

#endif //C2026_2027_MATRIX_H