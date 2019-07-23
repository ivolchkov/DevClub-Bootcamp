// Считать с клавиатуры три целых числа - первый член, шаг и количество членов арифметической прогрессии.
//  Вывести в строку через пробел члены заданной прогрессии. Задаваемое количество больше нуля.

#include <stdio.h>

int main() {
    int first, step, count;
    
    scanf("%d %d %d", &first, &step, &count);
    for ( int i = 1; i < count; i += 1 ) {
        printf("%d ", first);
        first += step;
    }
    printf("%d\n", first);
    
    return 0;
}
