#ifndef LAB_PROJECTS_2026_2027_POINT_H
#define LAB_PROJECTS_2026_2027_POINT_H
#include <cmath>
#include <iostream>

using namespace std;

class Point {
        double x, y;
public:
    Point() : x(0), y(0) {}
    Point(double x0, double y0) : x( x0 ), y( y0 ) {}

    double get_x() { return x; }
    double get_y() { return y; }

    void input() {
        std:: cout << "x, y: ";
        std:: cin >> x >> y;
    }

    void output() {
        std:: cout << "(" << x << ", " << y << ")";
    }
};

class Line {
    Point a, b;
public:
    void input() {
        a.input();
        b.input();
    }

    void output() {
        a.output();
        b.output();
    }

    Point center_of_segment() {
        double x_center = (a.get_x() + b.get_x())/2.0;
        double y_center = (a.get_y() + b.get_y())/2.0;
        Point p(x_center, y_center);
        return p;
    }

    double length() {
        return sqrt( pow( a.get_x()-b.get_x(), 2 ) + pow( a.get_y()-b.get_y(), 2 ) );
    }

    Point intercepting_lines ( Line& l1, Line& l2 );

};

class Triangle {
    Point a, b, c;
    Line l1, l2, l3;
public:

    void input() {
        l1.input();
        l2.input();
        l3.input();
    }

    void output() {
        l1.output();
        l2.output();
        l3.output();
    }

    double perimeter() {
        return l1.length() + l2.length() + l3.length();
    }

    double area() {
        double p = perimeter()/2;
        return sqrt( p * ( p - l1.length() ) * ( p - l2.length() ) * ( p - l3.length() ) );
    }

};


#endif //LAB_PROJECTS_2026_2027_POINT_H
