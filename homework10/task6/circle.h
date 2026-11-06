#ifndef C2026_2027_CIRCLE_H
#define C2026_2027_CIRCLE_H
#include <stdbool.h>
typedef struct Circle_ {
    double r;
    double x;
    double y;
} Circle;

void printCircle(Circle c);
bool inputCircle(Circle* c);

#endif //C2026_2027_CIRCLE_H