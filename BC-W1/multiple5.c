// Считать с клавиатуры целое положительное число.
// Вывести в строку все числа, кратные 5, от нуля до указанного числа включительно.

#include <stdio.h>

#define MULTIPLIER 5

int main() {
    int last;
    
    scanf("%d", &last);
    
    last -= last % MULTIPLIER;
    
    for ( int i = 0; i < last; i += MULTIPLIER ) {
        printf("%d ", i);
    }
    printf("%d\n", last);
    
    return 0;
}
