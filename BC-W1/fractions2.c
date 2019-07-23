// Вывести возрастающую последовательность всех несократимых дробей в промежутке от 0 до 1, знаменатель которых не превышает заданное число.
// Вводимое число не превышает 200

#include <stdio.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    if ( n < 201 ) {
        printf("0/1 ");
        for ( int p = 1, q = n, a = 0, b = 1; p != q; ) {
            int tempP = p;
            int tempQ = q;
            
            if ( p % 2 == 0 && q % 2 == 0 ) {
                p /= 2;
                q /= 2;
            }
            printf("%d/%d ", p, q);
            p = ((n + b) / q) * p - a;
            q = ((n + b) / q) * q - b;
            
            a = tempP;
            b = tempQ;
        }
        printf("1/1\n");
    }
    
    return 0;
}
