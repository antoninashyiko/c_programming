#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    double x;
    
    printf("Enter a real number");
    scanf("%lf", &x);
    
    int integer_part=(int)x; // interger cast - extracts the integer part of the real number
    printf("interger part: %d\n", integer_part);
    
    double fractional_part=fabs(x-integer_part);
    printf("fraction part: %.6f\n", fractional_part);
    
    double floor_value=floor(x);
    printf("floor value: %.6f\n", floor_value);
    
    double ceil_value=ceil(x);
    printf("ceil value: %.6f\n", ceil_value);
    
    double round_value=round(x);
    printf("round value: %.6f\n", round_value);
}
