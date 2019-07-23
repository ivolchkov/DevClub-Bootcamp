// Считать с клавиатуры целое положительное число. Если число является целой степенью двойки, вывести "yes", иначе вывести "no".

#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    for ( int i = number; i > 1; i >>= 1 ) {
        if ( i % 2 != 0 ) {
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 0;
}
