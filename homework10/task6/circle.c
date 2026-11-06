#include <stdio.h>
#include "circle.h"

void printCircle(Circle c) {
    if (c.r <= 0) {
        printf("invalid radius\n");
        return;
    }
    printf("your circle: radius=%.2lf, coordinates of center=(%.2lf, %.2lf)\n", c.r, c.x, c.y);
}
bool inputCircle(Circle* c) {
    printf("enter the radius: ");
    if (scanf("%lf", &c->r) != 1||c->r <= 0) {
        printf("invalid radius\n");
        return false;
    }
    printf("enter the coordinates of center (x0 y0): ");
    if (scanf("%lf %lf", &c->x, &c->y) != 2) {
        return false;
    }
    return true;
}