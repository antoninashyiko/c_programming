#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

MATRIX input_matrix(int n, int m) {
    MATRIX mat=(MATRIX)malloc(sizeof(double*)*n);
    if (mat==NULL) {
        return NULL;
    }
    for (int i=0; i<n; i++) {
        mat[i] = (double*)malloc(m * sizeof(double));
        if (mat[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
        printf("Enter elements for row %d: \n", i + 1);
        for (int j=0; j<m; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }
    return mat;
}
MATRIX add_row_matrix(const MATRIX mat, int n, int m) {
    if (mat == NULL) {
        return NULL;
    }
    MATRIX result=(MATRIX)malloc(sizeof(result[0])*(n+1));
    if (result==NULL) {
        return NULL;
    }
    for (int i=0; i<n+1; i++) {
        result[i]=(double*)malloc(m*sizeof(result[i][0]));
        if (result[i]==NULL) {
            delete_matrix(result, i);
            return NULL;
        }
        if (i==n) {
            printf("enter your extra row: ");
            for (int j=0; j<m; j++) {
                scanf("%lf", &result[i][j]);
            }
        }
        else {
            for (int j=0; j<m; j++) {
                result[i][j]=mat[i][j];
            }
        }
    }
    return result;
}
MATRIX multiply_matrix(const MATRIX mat1, MATRIX mat2, int n1, int m1, int n2, int m2) {
    if (m1 != n2) {
        return NULL;
    }
    MATRIX result=(MATRIX)malloc(sizeof(result[0])*n1);
    if (result == NULL) {
        return NULL;
    }
    for (int i=0; i<n1; i++) {
        result[i]=(double*)malloc(m2*sizeof(result[i][0]));
        if (result[i]==NULL) {
            delete_matrix(result, i);
            return NULL;
        }
        for (int j=0; j<m2; j++) {
            result[i][j] = 0.0;
            for (int k = 0; k < m1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}
void print_matrix(const MATRIX mat, int n, int m) {
    if (mat == NULL) return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%8.2lf ", mat[i][j]);
        }
        printf("\n");
    }
}
void delete_matrix(MATRIX mat, int n) {
    if (mat==NULL) {
        return;
    }
    for (int i=0; i<n; i++) {
        free(mat[i]);
    }
    free(mat);
}