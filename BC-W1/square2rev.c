// Условие задачи
// Вывести числовой квадрат заданного размера.
// Выведенные числа начинаются с единицы и постоянно увеличиваются.
// В каждой строке числа разделены пробелами.
// Порядок строк обратный.
// Размер считать с клавиатуры.


#include <stdio.h>

int main() {
    int square, value, check;
    
    scanf("%d", &square);
    value = square * square - (square - 1);
    check = value;
    for ( int line = 1; line <= square; line++ ) {
        for ( int column = 1; column < square; column++ ) {
            printf("%d ", value);
            value += 1;
        }
        printf("%d\n", value);
        check -= square;
        value = check;
    }
    
    return 0;
}
