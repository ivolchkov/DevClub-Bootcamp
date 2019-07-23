#include <iostream>

template <typename T>
T summ(T x, T y) {
    return x + y;
}

template <typename T, typename N>
N summ(int x = 10, N y) {
    return x + y;
}

int summ(int x, int y) {
    return x + y;
}

double summ(double x, double y) {
    return x + y;
}


int main() {
    int x = 5;
    int y = 7;
    double c = 3.14;
    double d = 5.5;
    
    std::cout<<summ(x,y)<<std::endl;
    std::cout<<summ(c,d)<<std::endl;
    
    return 0;
}
