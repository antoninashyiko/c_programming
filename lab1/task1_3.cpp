#include <stdio.h>
#include <math.h>

int main()
{
    int a;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("-%d -%d -%d\n", a, a, a);
    printf("%d|%d|%d\n", a, a, a);
    printf("-%d -%d -%d\n", a, a, a);
    return 0;
}