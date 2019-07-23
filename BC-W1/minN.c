// Считать с клавиатуры целое положительное число - количество чисел в последовательности.
// Затем считать с клавиатуры заданное количество чисел и вывести наименьшее из них.
// Данная задача решается без массивов.

#include <stdio.h>

int main() {
    int average, number;
    int min;
    
    scanf("%d%d", &average, &min);
    for ( int i = 1; i < average; i++ ) {
        scanf("%d", &number);
        if ( number < min ) {
            min = number;
        }
    }
    printf("%d\n", min);
    
    return 0;
}
