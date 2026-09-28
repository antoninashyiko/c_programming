#include <stdio.h>
#include <stdlib.h>

int func_d(int n) {     // пункт д
    if (n>9&&n<100) {
        unsigned units=n%10;
        unsigned tens=n/10;
        return (units+tens>9);
    }
    return 0;
}
double func_e(double x, double y) { // пункт е
    return (x-y>=7);
}
double func_eu(double x, double y, double z) { // пункт є
    return (x>99||y>99||z>99);
}
double func_j(double x, double y, double z) {
    if ((x<1001&&y>1001&&z>1001)||(x>1001&&y<1001&&z>1001)||(x>1001&&y>1001&&z<1001)) {
        return 1;
    }
    return 0;
}
int main() {
    int n;
    double x, y, z;
    printf("enter n: ");
    scanf("%d",&n);
    printf("enter x, y, z for next tasks: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("task d: %d", func_d(n));
    printf("task d: %lf", func_e(x,y));
    printf("task d: %lf", func_eu(x,y,z));
    printf("task d: %lf", func_j(x,y,z));
}