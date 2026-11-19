#include <iostream>

#ifndef LAB_PROJECTS_2026_2027_POINT_H
#define LAB_PROJECTS_2026_2027_POINT_H


class Point {
    double x, y;
    static int n;

public:
    Point(): x(0), y(0) {}
    Point ( double x_, double y_) : x(x_), y(y_) {
        n++;
    }

    void input() {
        std:: cout << "x, y: ";
        std:: cin >> x >> y;
        n++;
    }

    double length( const Point& p );

    static int counter() {
        return n;
    }
};


#endif //LAB_PROJECTS_2026_2027_POINT_H
