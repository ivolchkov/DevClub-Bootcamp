// Считать с клавиатуры целые числа min, max, m, n, причём m и n положительные.
// Вывести на экран в столбик целые числа от min до max включительно, которые без остатка делятся как на m, так и на n.
// В указанном промежутке гарантируется хотя бы одно число, подлежащее выводу.

#include <stdio.h>

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    int m, n, min, max;
    int lcm, multiple;
    
    scanf("%d %d %d %d", &min, &max, &m, &n);
    
    lcm = (m / gcd(m, n)) * n;
    
    multiple = min - min % lcm;
    if ( multiple < min ) {
        multiple += lcm;
    }
    for ( int i = multiple; i <= max; i += lcm ) {
        printf("%d\n", i);
    }
    return 0;
}
