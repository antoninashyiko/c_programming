#include <stdio.h>
#include <stdlib.h>

int maximum(int a, int b) {
    if (a>b) return a;
    return b;
}
int minimum(int a, int b) {
    return a<b ? a : b; // python: return a if a<b else return b
}
void task3_5() {
    int x, y;
    printf("enter two integers: ");
    scanf("%d %d", &x, &y);

    printf("Max(%d, %d) = %d\nMin(%d, %d) = %d\n", x, y, maximum(x, y), x, y, minimum(x, y));
}
int main() {
    task3_5();
}