#include <stdio.h>
int harm_max1(double a) {
    int i=1;
    double s=0;
    while (s<a) {
        s+=1.0/i;
        i++;
    }
    return i;
}
int harm_max2(double a) {
    int i=1;
    double s=0;
    while (s<=a) {
        s+=1.0/i;
        i++;
    }
    return i;
}
int main() {
    double a;
    printf("Enter a number: ");
    scanf("%lf", &a);
    printf("Harm max = %d\n", harm_max1(a));
    printf("Harm max2 = %d", harm_max2(a));
}