#include <iostream>
#include <math.h>

using namespace std;
double avg(float a, float b){
    return (a+b)/2.0;
}
double harmonic_mean(float a, float b){
    return 2.0/(1.0/a+1.0/b);
}
int main()
{
    float x, y;
    printf("Enter two real numbers: ");
    scanf("%f", &x);
    scanf("%f", &y);
    float sum=x+y;
    float diff=x-y;
    float prod=x*y;
    float quot=x/y;
    
    printf("sum= %f\n", sum);
    printf("diff= %f\n", diff);
    printf("prod= %f\n", prod);
    printf("quot= %f\n", quot);
    
    printf("average= %f\n", avg(x, y));
    printf("harmonic_mean= %f\n", harmonic_mean(x, y));
}
