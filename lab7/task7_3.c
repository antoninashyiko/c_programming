#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10

void task7_3() {
    double a[SIZE];
    for (int i=0; i<SIZE; i++){
        printf("enter a value for a[%d]=", i);
        scanf("%lf", &a[i]);
    }
    printf("you entered the following values for array a: \n");
    for (int i=0; i<SIZE; i++) {
        printf("%g", a[i]);
    }
    printf("\n");
    int count=0;
    for (int i=0; i<SIZE; i++) {
        if (a[i]>M_E) {
            count++;
        }
    }
    printf("the number of elements in the array bigger than e is: %d", count);
}