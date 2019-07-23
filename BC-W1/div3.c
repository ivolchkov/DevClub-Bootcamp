// Считать min, max. Вывести в столбик кратные тройке числа от min до max включительно.

#include <stdio.h>

int main() {
    int min, max, multiple;
    
    scanf("%d %d", &min, &max);
    multiple = min - min % 3;
    if ( multiple < min ) {
        multiple += 3;
    }
    for ( int i = multiple; i <= max; i += 3 ) {
        printf("%d\n", i);
    }
    return 0;
}
