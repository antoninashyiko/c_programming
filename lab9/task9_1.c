#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int input_array(unsigned n, double *arr) {
    for (unsigned int i=0; i<n; i++) {
        printf("enter element %u: ", i+1);
        scanf("%lf", &arr[i]);
        if (scanf("%lf", &arr[i]) != 1) {
            printf("wrong input\n");
            return i;
        }
    }
    return n;
}
void print_array(unsigned n, double *arr) {
    for (unsigned int i=0; i<n; i++) {
        printf("%g, ", arr[i]);
    }
    printf("\n");
}
double sum_sqrt(const double *arr, unsigned n) {
    double sum_sqrt=0.0;
    for (unsigned int i=0; i<n; i++) {
        sum_sqrt += arr[i]*arr[i];
    }
   return sum_sqrt;
}
int main() {
    unsigned int n;
    printf("enter n: ");
    scanf("%u", &n);
    double* arr=(double*)malloc(n*sizeof(double));
    if (arr==NULL) {
        printf("memory allocation failed\n");
        return EXIT_FAILURE;
    }
    input_array(n, arr);
    print_array(n, arr);
    printf("\n");
    
    printf("sum of sqrt: %lf\n", sum_sqrt(arr, n));

    free(arr);
    return EXIT_SUCCESS;
}