#include <stdio.h>
#include "info.h"

int main() {
    Plist p[]={
        {0, 'f', 160 },
        {1, 'm', 170 },
        {2, 'f', 175 },
        {3, 'm', 189 },
    };
    int count=sizeof(p) / sizeof(p[0]);
    Plist *p_ptrs[count];
    for (int i = 0; i < count; i++) {
        p_ptrs[i] = &p[i];
    }
    printf("teste plist: ");
    printf("women height average check: ");
    printf("%lf\n", women_height_average(p_ptrs, count));

    int n;
    printf("enter number of people: ");
    scanf("%d", &n);
    char L[n][MAX_LENGTH];
    Plist p1[n];
    Plist *ptrs[n];
    for (int i = 0; i < n; i++) {
        printf("Enter name for person %d: ", i + 1);
        scanf("%s", L[i]);

        printf("Enter gender (f/m) for person %d: ", i + 1);
        scanf(" %c", &p1[i].gender);

        printf("Enter height for person %d: ", i + 1);
        scanf("%lf", &p1[i].height);

        p1[i].number = i;
        ptrs[i] = &p1[i];
    }

    double avg = women_height_average(ptrs, n);
    printf("\nwomen height average: %lf\n", avg);
    if (n >= 2) {
        if (same_height_check(&p1[0], &p1[1])) {
            printf("these people have the same height\n");
            printf("%s and %s\n", L[0], L[1]);
        }
        else printf("these people do not have the same height\n");
    }
    else {
        printf("Not enough people to compare heights.\n");
    }

    return 0;

}