#include <stdio.h>
#include <math.h>
void input_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }
}
void print_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
double determinant(int n, double matrix[n][n]) {
    double det=1;
    double det2=matrix[0][0]*matrix[1][1]-matrix[1][0]*matrix[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            det*=matrix[i][i]*pow(-1, i+j)*det2;
        }
    }
    return det;
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    double matrix[n][n];
    printf("enter the n by n matrix: ");
    printf("\n");
    input_matrix(n, matrix);
    printf("your matrix is:\n");
    print_matrix(n, matrix);

    printf("\n");
    double det = determinant(n, matrix);
    printf("determinant is: %lf\n", det);
}