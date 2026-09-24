#include <iostream>
#include <math.h>

using namespace std;
int main()
{
    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);
    
    int y=x*x;
    y*=y; // power 4
    int y4=y;
    y*=y; // power 8
    int y8=y;
    y*=y; //power 16
    
    y*=y8; // power 24
    y*=y4; // power 28
    
    printf("x^28=%d\n", y);
}
