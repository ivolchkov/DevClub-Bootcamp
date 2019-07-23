// Вывести числовую пирамидку на total строк.
// В каждой строке числа идут от единицы до номера строки через пробел.

#include <stdio.h>

int main() {
    int total;
    
    scanf("%d", &total);
    
    for ( int row = 1; row <= total; row++ ) {
        for ( int col = 1; col < row; col++ ) {
            printf("%d ", col);
        }
        printf("%d\n", row);
    }
    
    return 0;
}

