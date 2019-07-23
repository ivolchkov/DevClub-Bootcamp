// Считать с клавиатуры целое положительное число - количество чисел в последовательности.
// Затем считать с клавиатуры заданное количество чисел и вывести наибольшее из них.

#include <stdio.h>

int main() {
    int average, number;
    int max;
    
    scanf("%d%d", &average, &max);
    for ( int i = 1; i < average; i++ ) {
        scanf("%d", &number);
        if ( number > max ) {
            max = number;
        }
    }
    printf("%d\n", max);
    
    return 0;
}
