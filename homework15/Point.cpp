//
// Created by Chocolate Chip on 20.11.2026.
//

#include "Point.h"

Point Line::intercepting_lines( Line& l1, Line& l2 ) {
    double x1 = l1.a.get_x();
    double y1 = l1.a.get_y();
    double x2 = l1.b.get_x();
    double y2 = l1.b.get_y();

    double x3 = l2.a.get_x();
    double y3 = l2.a.get_y();
    double x4 = l2.b.get_x();
    double y4 = l2.b.get_y();
    double denom = ( x2 - x1 ) * ( y4 - y3 ) - ( y2- y1 ) * ( x4 - x3 );
    if ( std::fabs(denom) < 1e-9 ) {
        std::cout<<"lines are parallel"<<std::endl; // або відповідно збігаються
        return Point();
    }

    double p = (( x3- x1 ) * ( y4 - y3 ) - ( y3- y1 ) * ( x4 - x3 ))/denom;
    double c = (( x3- x1 ) * ( y2 - y1 ) - ( y3- y1 ) * ( x2 - x1 ))/denom;

    if ( p >= 0 and p <= 1 and c >= 0 and c <= 1 ) {
        double x0 = x1 + p * ( x2 - x1 );
        double y0 = y1 + p * ( y2 - y1 );
        std::cout << "lines intercept \n";
        Point result = Point( x0, y0 );
        return result;
    }
    std::cout<< " lines dont intercept \n";
    return Point();
}

int main() {
    Line line1, line2;

    std::cout << "first line:\n";
    line1.input();

    std::cout << "second line:\n";
    line2.input();

    Point cross = line1.intercepting_lines(line1, line2);
    std::cout << "interception: ";
    cross.output();
    std::cout << "\n";

    std::cout << "length l1: " << line1.length() << "\n";
    std::cout << "center l1: ";
    line1.center_of_segment().output();
    std::cout << "\n";

    Triangle tr;
    std::cout << "input triangle:\n";
    tr.input();

    std::cout << "your triangle:\n: ";
    tr.output();
    std::cout << "\n";

    std::cout << "perimeter: " << tr.perimeter() << "\n";
    std::cout << "area: " << tr.area() << "\n";

    return 0;
}