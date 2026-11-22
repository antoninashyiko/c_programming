#include <iostream>

template <typename T>
T sum( T* x, size_t n ) {
    T sum = T();
    for ( size_t i = 0; i < n; ++i ) {
        sum += x[i];
    }
    return sum;
}

std::string sum( char* x, size_t n ) {
    std::string sum = " ";
    for ( size_t i = 0; i < n; ++i ) {
        sum += x[i];
    }
    return sum;
}

template <typename P>
P* sum( P** x, size_t n ) {
    P* sum = new P[n];
    for ( size_t i = 0; i < n; ++i ) {
        sum[i] = P(); // визначаємо, що це масив розміру 1
        if ( x[i]!=nullptr ) {
            sum[i] = *x[i];
        }
    }
    return sum;
}

int main() {

    int v1[3] ={ 1, 2, 3 };
    std::cout << sum(v1, 3) << std::endl;

    double v2[3] ={ 1.0, 2.0, 3.3 };
    std::cout << sum(v2, 3) << std::endl;

    std::string v3[3] = {"a", "bc", "def"};
    std::cout << sum(v3, 3) << std::endl;

    char v4[3] ={ 'a', 'b', 'c' };
    std::cout << sum(v4, 3) << std::endl;

    int a = 1;
    int b = 2;
    int c = 3;
    int* v5[] = { &a, &b, &c };
    int* res5 = sum(v5, 3);
    for (size_t i = 0; i < 3; i++) {
        std::cout << res5[i] << " ";
    }
    std::cout << std::endl;
    delete[] res5;
}