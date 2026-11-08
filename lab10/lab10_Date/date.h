#ifndef C2026_2027_DATE_H
#define C2026_2027_DATE_H
#include <stdbool.h>
typedef struct Date_ {
    int year;
    int month;
    int day;
} Date;
extern const int DAY_MONTH[];
extern void printDate(Date d);
extern bool leap_year(Date d);
extern int Day_Month(Date d);
extern bool inputDate(Date* d);
extern Date tomorrow(Date d);
extern Date yesterday(Date d);
extern void day_of_week(Date d);

#endif //C2026_2027_DATE_H