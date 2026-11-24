#include "stats.h"
#include <iostream>

int main() {
    size_t n;
    std:: cout << "enter amount of lines(1-50): ";
    std::cin >> n;
    if (n < 1 || n > 50) {
        std::cerr << "Error: amount of lines must be between 1 and 50" << std::endl;
        return 1;
    }

    Record record[50];
    for ( size_t i = 0; i < n; i++ ) {
        std::cout << "enter record: ";
        if (!(std::cin >> record[i].name >> record[i].score)) {
            std::cerr << "Error: incorrect format(name score expected)" << std::endl;
            return 1;
        }
    }

    try {
        Stats result = analyze( record, n );
        std:: cout << "Average score: " << result.average << std::endl;
        std:: cout << "Median: " << result.median << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

}
