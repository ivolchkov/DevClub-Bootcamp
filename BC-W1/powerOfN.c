// Считать с клавиатуры целое основание и целый неотрицательный показатель. Вывести через пробел степени числа основания от нулевой до заданной.

#include <stdio.h>

int main() {
    int number, index;
    int degree = 1;
    
    scanf("%d %d", &number, &index);
    
    for ( int i = 0; i < index; i++ ) {
        printf("%d ", degree);
        degree *= number;
    }
    
    printf("%d\n", degree);
    
    return 0;
}
