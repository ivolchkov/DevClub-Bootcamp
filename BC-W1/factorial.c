// Вычислить и вывести факториал считанного с клавиатуры целого числа.
// В случае неопределенности ответа вывести -1.
// Для решения пользоваться циклами.

#include <stdio.h>

int main() {
    int number;
    int factorial = 1;
    
    scanf("%d", &number);
    if ( number < 0 ) {
        printf("-1\n");
    } else {
        for ( int i = 1; i <= number; i++ ) {
            factorial *= i;
        }
        printf("%d\n", factorial);
    }
    return 0;
}
