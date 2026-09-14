#include <stdio.h>
#include <math.h>

double area_torus(double r, double R){
    return 2*pow(M_PI, 2)*R*r*r;
}
int test_area_torus() {
    if (fabs(area_torus(1, 2)-39.478)>1e-3) {
        printf("test for torus has failed\n");
        return 1;
    }
    return 0;
}
int main() {
    if (test_area_torus()==0) {
        printf("test for area_torus has succeeded\n");
    }
    double r, R;
    printf("Enter the radiuses of the sphere r and R: ");
    scanf("%lf %lf", &r, &R);
    if (R < r) {
        printf("Error: Major radius R must be greater than or equal to minor radius r\n");
        return 1;
    }
    printf("the area of the torus = %lf\n", area_torus(r,R));
}