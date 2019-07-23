// Вывести в консоль числовую пирамидку на total строк.
// В каждой строке числа идут от единицы до номера строки через пробел.
// Пропустить rows строк и cols столбцов.
// В выводе не должно быть пустых строк до и после чисел.
// Целые положительные числа total, rows и cols считать с клавиатуры.

#include <stdio.h>

int main() {
    int total, rows, cols;
    
    scanf("%d %d %d", &total, &rows, &cols);
    if ( rows < cols ) {
        rows = cols;
    }
    for ( int line = rows; line < total; line++ ) {
        rows += 1;
        for ( int column = cols + 1; column < rows; column++ ) {
            printf("%d ", column);
        }
        printf("%d\n", rows);
    }
    return 0;
}
