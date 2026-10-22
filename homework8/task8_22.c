#include <stdio.h>
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
            printf("%.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}
void mirror_matrix(int n, double matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n/2; j++) {
                double temp = matrix[i][n-1-j];
                matrix[i][n-1-j] = matrix[i][j];
                matrix[i][j] = temp;
        }
    }
}
int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int size=2*n+1;

    double matrix[size][size];
    printf("enter the %d by %d matrix: ", size, size);
    printf("\n");
    input_matrix(size, matrix);
    printf("your matrix is:\n");
    print_matrix(size, matrix);

    mirror_matrix(size, matrix);
    printf("your mirrored matrix is:\n");
    print_matrix(size, matrix);
}