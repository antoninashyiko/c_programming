#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
int main() {
    int a;
    printf("enter the number of matrices: ");
    scanf("%d", &a);
    MATRIX *matrix_list = (MATRIX*)malloc(sizeof(MATRIX) * a);
    int *n = (int*)malloc(sizeof(int) * a);
    int *m = (int*)malloc(sizeof(int) * a);
    if (matrix_list == NULL) return 1;
    for (int i = 0; i < a; i++) { // filling the list with different matrices
        printf("enter number of rows: ");
        scanf("%d", &n[i]);
        printf("enter number of collums: ");
        scanf("%d", &m[i]);
        matrix_list[i]=input_matrix(n[i], m[i]);
        if (matrix_list[i] == NULL) {
            for (int j = 0; j < i; j++) {
                delete_matrix(matrix_list[j], n[j]);
            }
            free(matrix_list);
            free(n);
            free(m);
            return 1;
        }
    }
    printf("your matrix list:\n");
    for (int i = 0; i < a; i++) {
        printf("matrix[%d]:\n", i);
        print_matrix(matrix_list[i], n[i], m[i]);
    }
    printf("\n");

    MATRIX matrix_list_product=matrix_list[0];
    int current_rows = n[0];
    int current_cols = m[0];
    for (int i = 1; i < a; i++) {
        if (current_cols != n[i]) {
            printf("Multiplication failed at step %d.\n", i + 1);
            break;
        }
        MATRIX next_product = multiply_matrix(
            matrix_list_product, matrix_list[i],
            current_rows, current_cols,
            n[i], m[i]
        );

        if (next_product == NULL) {
            printf("Multiplication failed at step %d.\n", i + 1);
            break;
        }
        matrix_list_product = next_product;
        current_cols = m[i];
    }
    printf("your matrix product:\n");
    print_matrix(matrix_list_product, current_rows, current_cols);


    for (int i = 0; i < a; i++) {
        delete_matrix(matrix_list[i], n[i]);
    }
    delete_matrix(matrix_list_product, current_rows);

    free(matrix_list);
    free(n);
    free(m);
    return 0;
}