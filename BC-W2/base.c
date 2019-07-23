// Считать с клавиатуры целое неотрицательное число в десятичной системе счисления и основание новой системы счисления (целое число от 2 до 10).
// Вывести в консоль число, записанное в новой системе счисления.
// Задача решается без массивов.

#include <stdio.h>

int main() {
    int number, base;
    int maxPower;
    
    scanf("%d %d", &number, &base);
    
    maxPower = 1;
    for ( int limit = number / base; maxPower <= limit; maxPower *= base );
    
    for ( ; maxPower > 1; maxPower /= base ) {
        int result = number / maxPower;
        
        if ( result != 0 ) {
            number %= maxPower;
        }
        printf("%d", result);
    }
    printf("%d\n", number/maxPower);
    
    return 0;
}
