#include <stdio.h>
unsigned sum_of_digits(unsigned n){
    unsigned units=n%10;
    unsigned tens=(n/10)%10;
    unsigned hundreds=n/100;
    
    return units+tens+hundreds;
}
unsigned inverse(unsigned n){
    unsigned units=n%10;
    unsigned tens=(n/10)%10;
    unsigned hundreds=n/100;
    
    return 100*units+10*tens+hundreds;
}
void print_combinations(unsigned n) {
    printf("combinatios: %u\n", n);
    unsigned units=n%10;
    unsigned tens=(n/10)%10;
    unsigned hundreds=n/100;
    if (units==tens||units==hundreds||tens==hundreds) {
        printf("not all digits are unique\n");
        return;
    }
    printf("%u %u %u\n", hundreds, tens, units);
    printf("%u %u %u\n", units, tens, hundreds);
    printf("%u %u %u\n", units, hundreds, tens);
    printf("%u %u %u\n", tens, units, hundreds);
    printf("%u %u %u\n", tens, hundreds, units);
    printf("%u %u %u\n", hundreds, units, tens);
}

int main()
{
    unsigned x;
    printf("enter a number: ");
    scanf("%u", &x);
    printf("you entered: %u\n", x);
    if (x>99 && x<1000){
        unsigned units=x%10;
        printf("units digit: %hhu\n", units);
        
        unsigned tens=(x/10)%10;
        printf("tens digit: %hhu\n", tens);
        
        unsigned hundreds=x/100;
        printf("hundreds digit: %hu\n", hundreds);
        
        printf("sum of digits: %u\n", sum_of_digits(x));
        printf("inverse: %u\n", inverse(x));
        
        printf("combinations");
        print_combinations(x);
    }
    else{
        printf("you entered not a three digit number");
    }
    return 0;
}