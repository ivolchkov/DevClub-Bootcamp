// Вывести числовую пирамидку на total строк. Порядок строк – обратный.
// В каждой строке числа идут от единицы до номера строки через пробел.

#include <stdio.h>

int main() {
    int pyramid;
    
    scanf("%d", &pyramid);
    for ( int line = pyramid; line > 0; line-- ) {
        for ( int column = 1; column < line; column++ ) {
            printf("%d ", column);
        }
        printf("%d\n", line);
    }
    
    return 0;
}
