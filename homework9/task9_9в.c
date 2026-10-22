#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
int main() {
    int n;
    printf("enter number of rows: ");
    scanf("%d", &n);
    int m;
    printf("enter number of collums: ");
    scanf("%d", &m);
    MATRIX mat=input_matrix(n, m);
    if (mat==NULL) {
        return 1;
    }
    MATRIX new_matrix=add_row_matrix(mat,n, m);
    if (new_matrix==NULL) {
        return 1;
    }
    printf("your new matrix:\n");
    print_matrix(new_matrix,n+1, m);

    delete_matrix(mat, n);
    delete_matrix(new_matrix, n);

    return 0;
}