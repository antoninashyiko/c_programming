#ifndef C2026_2027_GEOMETRY_H
#define C2026_2027_GEOMETRY_H
#include <stdbool.h>

typedef double GTYPE;

typedef struct TPOINT_ {
    GTYPE x;
    GTYPE y;
} TPOINT;
typedef struct RECT_ {
    TPOINT A;
    TPOINT B;
} RECT;

extern void printPoint(const TPOINT *p);
extern bool inputPoint(TPOINT *p);

extern void printRect(const RECT *p);
extern bool inputRect(RECT *p);

#endif //C2026_2027_GEOMETRY_H