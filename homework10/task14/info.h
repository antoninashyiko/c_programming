#ifndef C2026_2027_INFO_H
#define C2026_2027_INFO_H
#include <stdbool.h>
#define MAX_LENGTH 50

typedef struct Plist_{
    int number;
    char gender;
    double height;
} Plist;

extern double women_height_average(Plist* p[], int count);
extern bool same_height_check(Plist* p1, Plist* p2);

#endif //C2026_2027_INFO_H