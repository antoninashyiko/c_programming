#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 5
int input_array(int mas[], int size) {
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
void print_array(int mas[], int size) {
    int i=0;
    for (i=0; i<size; i++) {
        printf("%d ", mas[i]);
    }
    printf("\n");
}
int max_array(int mas[], int size) {
    int max=mas[0];
    for (int i=1; i<size; i++) {
        if (max<mas[i]) {
            max=mas[i];
        }
    }
    return max;
}
int main() {
    int mas[SIZE];
    input_array(mas, SIZE);
    print_array(mas, SIZE);
    printf("max in array: %d\n", max_array(mas, SIZE));
}