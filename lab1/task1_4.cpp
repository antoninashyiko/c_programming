#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    double m1, m2, r, F;
    const double G=6.67430e-11;
    
    printf("Enter mass of the first object (kg): ");
    scanf("%lf", &m1);
    printf("Enter mass of the second object (kg): ");
    scanf("%lf", &m2);
    printf("Enter distance between objects (m): ");
    scanf("%lf", &r);
    
    F=G*(m1*m2)/(r*r);
    printf("Gravitational force: %e or %g N\n", F, F);
}