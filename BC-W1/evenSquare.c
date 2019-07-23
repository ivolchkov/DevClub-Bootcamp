// Считать с клавиатуры целые числа min и max. Вывести в строку квадраты всех четных чисел в промежутке от min до max включительно.
//  В указанном промежутке гарантированно существует как минимум 1 парное число.

#include <stdio.h>

int main() {
    int min, max, maxValue;
    
    scanf("%d %d", &min, &max);
    if ( min < 0 ) {
        min -= min % 2;
    }
    if ( max < 0 ) {
        max += max % 2;
    }
    min += min % 2;
    max -= max % 2;
    for ( int i = min; i < max; i += 2 ) {
        maxValue = i * i;
        printf("%d ", maxValue);
    }
    printf("%d\n", max*max);
    return 0;
}
