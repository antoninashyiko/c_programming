#include <stdio.h>
#include <stdlib.h>

void task7_2() {
    int mas[]={5, 112, 4, 3};
    for (int i=sizeof(mas)/sizeof(mas[0]); i>=0; i--) {
        printf("%d", mas[i]);
    }
    printf("\n");
}

int main() {
    task7_2();
}