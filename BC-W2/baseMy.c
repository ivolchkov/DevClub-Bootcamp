// Считать с клавиатуры целое неотрицательное число в десятичной системе счисления и основание новой системы счисления (целое число от 2 до 10).
// Вывести в консоль число, записанное в новой системе счисления.
// Задача решается без массивов.

#include <stdio.h>

int main() {
    int source, base;
    int maxPower = 1;
    
    scanf("%d %d", &source, &base);
    
    for ( int limit = source / 2; maxPower <= limit; maxPower *= base );
    for ( ; maxPower > 1; maxPower /= base ) {
        int result = source / maxPower;
        
        source %= maxPower;
        printf("%d", result);
    }
    printf("%d\n", source / maxPower);
    
    return 0;
}
