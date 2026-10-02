#include <stdio.h>
#define MAX_FOR_TASK6 20
double input_array(double mas[], int size) {
    int i=0;
    for (i=0; i<size; i++) {
        printf("Enter element %d: ", i);
        if (scanf("%d", &mas[i]) != 1) {
            printf("wrong input\n");
            return i;
        }
    }
    return i;
}
void print_array(double mas[], int size) {
    int i=0;
    for (i=0; i<size; i++) {
        printf("%d ", mas[i]);
    }
    printf("\n");
}
void add_arrays(double a[], double b[], double c[], int size) {
    int i=0;
    for (i=0; i<size; i++) {
        c[i]=a[i]+b[i];
    }
    print_array(c, size);
}
double scalar_mult(double a[], double b[], int size) {
    double c[size];
    int i=0;
    for (i=0; i<size; i++) {
        c[i]=a[i]*b[i];
    }
    print_array(c, size);
}
void task6() {
    //input dimension
    size_t size;
    printf("enter size of array (up to %d): ", MAX_FOR_TASK6);
    scanf("%zu", &size);
    if (size>MAX_FOR_TASK6) {
        size=MAX_FOR_TASK6;
    }
    // declare vectors
    double v1[MAX_FOR_TASK6];
    double v2[MAX_FOR_TASK6];
    double v3[MAX_FOR_TASK6];
    input_array(v1, size);
    printf("you entered the following values for array v1:\n");
    print_array(v1, size);
    input_array(v2, size);
    printf("you entered the following values for array v1:\n");
    print_array(v2, size);
    input_array(v3, size);
    printf("you entered the following values for array v1:\n");
    print_array(v3, size);

    add_arrays(v1, v2, v3, size);
    printf("the result of adding v1 and v2 is stored in v3:\n");
    print_array(v3, size);

    double scalar=scalar_mult(v1, v2, size);

    printf("the result of multiplying v1 by %g is stored in v3:\n", scalar);
    printf("%g\n", scalar);
}
int main() {
    task6();
}