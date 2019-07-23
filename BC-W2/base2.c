// Считать с клавиатуры целое число в десятичной системе счисления и основание новой системы счисления (целое число от 2 до 36).
// Вывести в консоль число, записанное в новой системе счисления.
// В качестве цифр, превышающих 9, использовать заглавные буквы латинского алфавита.
// Для решения можно пользоваться только циклами. Задача решается без массивов. Использовать только тип int.

#include <stdio.h>

int main() {
    int source, base, result;
    int maxPower = 1;
    
    scanf("%d %d", &source, &base);
    
    if ( source < 0 ) {
        source *= -1;
        printf("-");
    }
    for ( int i = source / base; i > 0; i /= base ) {
        maxPower *= base;
    }
    for ( ; maxPower >= base; maxPower /= base ) {
        result = source / maxPower;
        
        if ( result > 9 ) {
            printf("%c", result+55);
        } else {
            printf("%d", result);
        }
        source %= maxPower;
    }
    result = source / maxPower;
    if ( result > 9 ) {
        printf("%c\n", result+55);
    } else {
        printf("%d\n", result);
    }
    
    return 0;
}
