// Считать с клавиатуры целое положительное число.
// Вывести в строку через пробел по порядку все натуральные числа, не превышающие заданное.

#include <stdio.h>

int main() {
    int last;
    
    scanf("%d", &last);
    
    for ( int i = 1; i < last; i++ ) {
        printf("%d ", i);
    }
    printf("%d\n", last);
    
    return 0;
}
