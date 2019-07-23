//Считать с клавиатуры целое число.
//Если число чётное, вывести на экран yes, в противном случае вывести no.

#include <stdio.h>

int main() {
    int a;
    
    scanf("%d", &a);
    
    if ( a % 2 == 1 ) {
        printf("no\n");
    } else {
        printf("yes\n");
    }
    
    return 0;
}
