// Считать с клавиатуры целое положительное число, вывести на экран количество всех делителей этого числа.

#include <stdio.h>

int main() {
    int number;
    int counter = 0;
    
    scanf("%d", &number);
    
    for ( int i = 1; i <= number; i++ ) {
        if ( number % i == 0 ) {
            counter += 1;
        }
    }
    printf("%d\n", counter);
    return 0;
}
