// Считать с клавиатуры целое положительное число.
// Вывести в строку все чётные числа от нуля до указанного числа включительно.

#include <stdio.h>

int main() {
    int number, last;
    
    scanf("%d", &number);
    last = number - number % 2;
    for ( int i = 0; i < last; i += 2 ) {
        printf("%d ", i);
    }
    printf("%d\n", last);
    return 0;
}
