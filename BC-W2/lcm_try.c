#include <stdio.h>


int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    int a, b;
    int lcm;
    
    a = 3;
    b = 5;
    
    lcm = a * b / gcd(a , b);
    
    printf("%d\n", lcm);
}
