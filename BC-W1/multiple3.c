// Считать с клавиатуры целое положительное число.
// Вывести в строку все числа, кратные 3, от нуля до указанного числа включительно.

#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    number = number - number % 3;
    
    for ( int i = 0; i < number; i += 3 ) {
        printf("%d ", i);
    }
    
    printf("%d\n", number);
    
    return 0;
}
