// Считать min, max. Вывести в столбик чётные числа от min до max включительно.

#include <stdio.h>

int main() {
    int min, max;
    
    scanf("%d %d", &min, &max);
    if ( min % 2 != 0 ) {
        min += 1;
    }
    for ( int i = min; i <= max; i += 2 ) {
        printf("%d\n", i);
    }
    return 0;
}
