#include <stdio.h>
#include <math.h>

int main()
{
    double T=365+1.0/(4+(1.0/(7+(1.0/(1+1.0/3)))));
    printf("period of earth's rotation around the sun = %.2f\n", T);
}