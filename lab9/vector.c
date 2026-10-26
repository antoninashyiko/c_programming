#include "vector.h"

#include <stdio.h>
#include <stdlib.h>

double* input_vector(int n) {
    double* v=(double*)malloc(sizeof(double)*n);
    for(int i=0;i<n;i++) {
        printf("enter element %d: ",i);
        scanf("%lf",&v[i]);
    }
    return v;
}
double* add_vectors(const double* v1, const double* v2, int n) {
    double* v_sum=(double*)malloc(sizeof(double)*n);
    for(int i=0;i<n;i++) {
        v_sum[i]=v1[i]+v2[i];
    }
    return v_sum;
}
double* subtract_vectors(const double* v1, const double* v2, int n) {
    double* v_sub=(double*)malloc(sizeof(double)*n);
    for(int i=0;i<n;i++) {
        v_sub[i]=v1[i]-v2[i];
    }
    return v_sub;
}
void print_vector(const double* v, int n) {
    for(int i=0;i<n;i++) {
        printf("%lf ",v[i]);
    }
    printf("\n");
}
void delete_vector(double* v) {
    free(v);
}