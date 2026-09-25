#include <stdio.h>
#include <stdlib.h>
int absolute(int a) {
    return (a<0)?a:-a;
}
int maximum(int a, int b, int c){
    int d=abs(a);
    if (abs(a)<abs(b)){
        d=abs(b);
    }
    else if (abs(c)>d){
        d=abs(c);
    }
    return d;
}
int minimum(int a, int b, int c){
    int d=abs(a);
    if (abs(a)>abs(b)){
        d=abs(b);
    }
    else if (abs(c)>d){
        d=abs(c);
    }
    return d;
}

int main()
{
    int x, y, z;
    printf("enter three number: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("maximum by module: %d\n", maximum(x, y, z));
    printf("minimum by module: %d\n", minimum(x, y, z));
    return 0;
}