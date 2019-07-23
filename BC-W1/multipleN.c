// Считать с клавиатуры целое неотрицательное число-максимум.
// Считать с клавиатуры целый, не равный нулю делитель.
// Вывести в строку числа от нуля до указанного максимума включительно, кратные заданному делителю.

#include <stdio.h>

int main() {
    int max, divider;
    
    scanf("%d %d", &max, &divider);
    max -= max % divider;
    if ( divider < 0 ) {
        divider = -divider;
    }
    for ( int i = 0; i < max; i += divider ) {
        printf("%d ", i);
    }
    printf("%d\n", max);
    return 0;
}
