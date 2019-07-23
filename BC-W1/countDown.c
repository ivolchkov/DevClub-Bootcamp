//Считать с клавиатуры целое неотрицательное число.
// Вывести в строку убывающий ряд чисел от заданного до нуля.

#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    for ( number = number; number > 0; number-- ) {
        printf("%d ", number);
    }
    printf("0\n");
    
    return 0;
}
