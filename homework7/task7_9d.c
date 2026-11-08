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
int max_array_odd(int mas[], int size) {
    int max=mas[0];
    for (int i=2; i<size; i+=2) {
        if (max<mas[i]) {
            max=mas[i];
        }
    }
    return max;
}
int min_array_even(int mas[], int size) {
    int min=mas[1];
    for (int i=3; i<size; i+=2) {
        if (min<mas[i]) {
            min=mas[i];
        }
    }
    return min;
}
int main() {
    int mas[SIZE];
    input_array(mas, SIZE);
    print_array(mas, SIZE);
    printf("task7_9 d answer: %d\n", max_array_odd(mas, SIZE)+min_array_even(mas, SIZE));
}