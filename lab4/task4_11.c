#include <stdio.h>
int main() {
    double sum=0;
    int x, k=0;
    do {
        printf("a[%d]=", k);
        scanf("%d", &x);
        k++;
        sum+=x;
    } while (x!=0);
    printf("avg = %d", sum/k);
}