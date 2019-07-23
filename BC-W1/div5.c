// Считать min, max. Вывести в столбик кратные пяти числа от min до max включительно.

#include <stdio.h>

int main() {
    int min, max, multiple;
    
    scanf("%d %d", &min, &max);
    multiple = min - min % 5;
    if ( multiple < min ) {
        multiple += 5;
    }
    for ( int i = multiple; i <= max; i += 5 ) {
        printf("%d\n", i);
    }
    return 0;
}
