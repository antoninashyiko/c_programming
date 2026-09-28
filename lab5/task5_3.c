#include <stdio.h>
// finish writing
int kollatz(int a, int n) {
    int a0=a, a1;
    for (int k=0; k<=n; k+=1) {
        if (a0%2==0) {
            a=a0/2;
            a0=a;
        }
        else {
            a=a0*3+1;
            a0=a;
        }
    }
    return a;
}
int count_till_one(int a) {
    int count=1, b=a;
    while (b!=1) {
        a=kollatz(a,count);
        count++;
    }
    return count;
}
int main() {
    int max=0;
    for (int i=1; i<=100; i++) {
        printf("%d\n", count_till_one(i));
    }
}