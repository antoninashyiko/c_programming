#include <stdio.h>
#define MAX_FOR_TASK5 50
int input_unsigned_array(unsigned int mas[]) {
    int i;
    for (i=0; i<MAX_FOR_TASK5; i++ ) {
        printf("enter a value for mas[%d]: ", i);
        if (scanf("%d", &mas[i]) != 1) {
            printf("invalid input\n");
            return i;
        }
        if (mas[i]==0) {
            break;
        }
    }
    return i;
}
void print_even_odd(const unsigned int mas[], int size) {
    int even_count=0;
    int odd_count=0;
    for (int i=0; i<size; i++) {
        if (mas[i]%2==0) {
            even_count++;
        }
        else {
            odd_count++;
        }
    }
    printf("number of even numbers: %d", even_count);
    printf("number of odd numbers: %d", odd_count);
}
int main() {
    unsigned int mas[MAX_FOR_TASK5];
    int actual_size = input_unsigned_array(mas);
    print_even_odd(mas, actual_size);
}