// Условие задачи
// Вывести числовой квадрат заданного размера.
// Выведенные числа начинаются с единицы и постоянно увеличиваются.
// В каждой строке числа разделены пробелами.
// Размер считать с клавиатуры.

#include <stdio.h>

int main() {
    int square;
    int value = 1;
    
    scanf("%d", &square);
    for ( int line = 1; line <= square; line++ ) {
        for ( int column = 1; column < square; column++ ) {
            printf("%d ", value);
            value += 1;
        }
        printf("%d\n", value);
        value += 1;
    }
    
    return 0;
}
