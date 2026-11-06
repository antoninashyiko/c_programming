#include "info.h"

double women_height_average(Plist* p[], int count) {
    double sum=0;
    int n=0;
    for (int i = 0; i < count; i++) {
        if (p[i]->gender == 'f'||p[i]->gender == 'F') {
            sum+=p[i]->height;
            n++;
        }
    }
    if (n==0) return sum;
    return sum/n;
}
bool same_height_check(Plist* p1, Plist* p2) {
    return p1->height==p2->height;
}