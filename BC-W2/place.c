// Считать с клавиатуры целое число.
// Вывести на экран количество знакомест, нужных для вывода этого числа.

#include <stdio.h>

int main() {
    int source;
    int count = 0;
    
    scanf("%d", &source);
    
    if ( source <= 0 ) {
        count += 1;
        source = -source;
    }
    for ( ; source > 0; source /= 10 ) {
        if ( source > 0 ) {
            count += 1;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
