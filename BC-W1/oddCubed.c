// Считать с клавиатуры целые числа min и max. Вывести в строку кубы всех нечетных чисел в промежутке от min до max включительно.
//  В указаном промежутке гарантированно существует минимум одно нечетное число.

#include <stdio.h>

int main() {
    int min, max, maxValue;
    
    scanf("%d %d", &min, &max);
    
    if ( min % 2 == 0 ) {
        min += 1;
    }
    if ( max % 2 == 0 ) {
        max -= 1;
    }
    
    for ( int i = min; i < max; i += 2 ) {
        maxValue = i * i * i;
        printf("%d ", maxValue);
    }
    max = max * max * max;
    printf("%d\n", max);
    return 0;
}
