// Считать с клавиатуры целое неотрицательное число. Вывести через пробел степени числа 2 от нулевой до заданной. Использовать цикл.

#include <stdio.h>

int main() {
    int number;
    int degree = 1;
    
    scanf("%d", &number);
    
    for ( int i = 0; i < number; i++ ) {
        printf("%d ", degree);
        degree *= 2;
    }
    
    printf("%d\n", degree);
    
    return 0;
}
