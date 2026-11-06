#include <stdio.h>
#include "circle.h"

int main() {
    Circle c[]={
        {56, 0, 0},
        {1, 1, 1},
        {-5, -6, -7}
    };
    int n=sizeof(c)/sizeof(c[0]);
    printf("test circles output: \n");
    for (int i=0; i<n; i++) {
        printf("test number {%d}\n", i+1);
        printCircle(c[i]);
        printf("\n");
    }

    Circle circle;
    inputCircle(&circle);
    printf("your circle: ");
    printCircle(circle);
}