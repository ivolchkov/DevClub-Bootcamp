// Считать с клавиатуры целые числа min, max и положительный делитель. Вывести в столбик числа, кратные делителю, от min до max включительно.

#include <stdio.h>

int main() {
    int min, max, multiple, divisor;
    
    scanf("%d %d %d", &min, &max, &divisor);
    /*if ( divisor < 0 ) {
        divisor = -divisor;   Bender doesn`t like it, but it is necessary for negative divisors.
    }*/
    multiple = min - min % divisor;
    if ( multiple < min ) {
        multiple += divisor;
    }
    for ( int i = multiple; i <= max; i += divisor ) {
        printf("%d\n", i);
    }
    return 0;
}
