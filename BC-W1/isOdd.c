//Считать с клавиатуры целое число.
//Если число нечётное, вывести на экран yes, в противном случае вывести no.

#include <stdio.h>

int main() {
    int a;
    
    scanf("%d", &a);
    
    if ( a % 2 != 1 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}
