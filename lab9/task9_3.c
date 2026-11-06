#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "vector.h"

int main() {
    int n;
    printf("Enter size of the vectors: ");
    scanf("%d", &n);

    double* v1 = input_vector(n);
    double* v2 = input_vector(n);

    double* v_sum=add_vectors(v1, v2, n);
    double* v_sub=subtract_vectors(v1, v2, n);

    printf("the sum of the vectors is: ");
    print_vector(v_sum, n);
    printf("the subtraction of the vectors is: ");
    print_vector(v_sub, n);

    delete_vector(v_sum);
    delete_vector(v_sub);
    delete_vector(v1);
    delete_vector(v2);
}