#include <stdio.h>
int first_positive() {
    int x1=-99, x2=-99, x3=-99, x=0, k=3;
    while (x<=0) {
        x=x1+x3+100;
        x1=x2;
        x2=x3;
        x3=x;
        k++;
    }
    return k;
}
int main() {
    printf("%d\n", first_positive());
}