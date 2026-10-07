#include <stdio.h>
#define SIZE 5
int number_of_elements_less_than_a(const int mas[], int size, double a) {
    int count=0;
    for (int i=0;i<size;i++) {
        if (mas[i]<a) {
            count++;
        }
    }
    return count;
}
void task1() {
    int mas[]={1, 7, 2, 4, 5};
    double a;
    int k=0;
    printf("enter a value for a: ");
    scanf("%lf", &a);

    for (int i=0;i<SIZE;i++) { // print array
        if (mas[i]<a) {
            printf("%d ", mas[i]);
            k++;
        }
    }
    printf("\nNumber of elements less than %g: %d\n", a, k);
    // second way
    int count=number_of_elements_less_than_a(mas, SIZE, a);
    printf("\nNumber of elements less than %g: %d\n", a, count);
}
int main() {
    task1();
}