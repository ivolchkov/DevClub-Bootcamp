// Написать функцию, которая находит наибольший общий делитель.
// int gcd(int a, int b)
#include <stdio.h>


int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    int a, b;
    
    a = 120;
    b = 250;
    
    gcd(a , b);
    
    printf("%d\n", gcd(a,b));
}
