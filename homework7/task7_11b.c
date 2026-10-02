#include <stdio.h>
void print_array(double mas[], int size) {
    int i=0;
    for (i=0; i<size; i++) {
        printf("%d ", mas[i]);
    }
    printf("\n");
}
void polynom_Ermit(int n, double x) {
    double Hn[n];
    Hn[0]=1;
    Hn[1]=2*x;
    for (int i=2; i<n; i++) {
        Hn[i]=2*x*Hn[i-1]-2*(i-1)*Hn[i-2];
    }
    print_array(Hn, n);
}
int main() {
    int n;
    double x;
    do {
        printf("enter a number n<256: ");
        scanf("%d", &n);
    } while (n>=256);
    printf("enter a number x: ");
    scanf("%lf", &x);
    polynom_Ermit(n, x);
}