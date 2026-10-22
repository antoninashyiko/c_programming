#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

MATRIX input_matrix(int n) {
    MATRIX mat=(MATRIX)malloc(sizeof(double*)*n);
    if (mat==NULL) {
        return NULL;
    }
    for (int i=0; i<n; i++) {
        mat[i] = (double*)malloc(n * sizeof(double));
        if (mat[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(mat[j]);
            }
            free(mat);
            return NULL;
        }
        printf("Enter elements for row %d: \n", i + 1);
        for (int j=0; j<n; j++) {
            scanf("%lf", &mat[i][j]);
        }
    }
    return mat;
}
MATRIX add_matrix(const MATRIX mat1, const MATRIX mat2, int n1, int n2) {
    if (n1!=n2) {
        return NULL;
    }
    MATRIX result=(MATRIX)malloc(sizeof(result[0])*n1);
    if (result==NULL) {
        return NULL;
    }
    for (int i=0; i<n1; i++) {
        result[i]=(double*)malloc(n1*sizeof(result[i][0]));
        if (result[i]==NULL) {
            delete_matrix(result, i);
            return NULL;
        }
        for (int j=0; j<n1; j++) {
            result[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    return result;
}
MATRIX multiply_matrix(const MATRIX mat1, MATRIX mat2, int n1, int n2) {
    if (n1!=n2) {
        return NULL;
    }
    MATRIX result=(MATRIX)malloc(sizeof(result[0])*n1);
    if (result == NULL) { // <-- THIS CHECK IS MISSING
        return NULL;
    }
    for (int i=0; i<n1; i++) {
        result[i]=(double*)malloc(n1*sizeof(result[i][0]));
        if (result[i]==NULL) {
            delete_matrix(result, i);
            return NULL;
        }
        for (int j=0; j<n1; j++) {
            result[i][j]=mat1[i][j]*mat2[i][j];
        }
    }
    return result;
}
void print_matrix(const MATRIX mat, int n) {
    if (mat == NULL) return;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
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