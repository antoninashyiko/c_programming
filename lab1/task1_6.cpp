#include <stdio.h>
#include <math.h>

int main()
{
    float C;
    printf("Enter degrees in C: ");
    scanf("%f", &C);
    float F=9*C/5+32;
    printf("Degrees in F = %.2f\n", F);
    return 0;
}