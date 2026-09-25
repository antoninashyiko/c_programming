#include <stdio.h>
#include <math.h>

double volume_torus(double r, double R){
    return 2*pow(M_PI, 2)*R*r*r;
}
int test_volume_torus() {
    if (fabs(volume_torus(1, 2)-39.478)>1e-3) {
        printf("test for torus has failed\n");
        return 1;
    }
    return 0;
}
int main() {
    test_volume_torus();
    double r, R;
    printf("Enter the radiuses of the torus r and R: ");
    scanf("%lf %lf", &r, &R);
    if (R < r) {
        printf("Error: Major radius R must be greater than or equal to minor radius r\n");
        return 1;
    }
    printf("the area of the torus = %lf\n", volume_torus(r,R));
}