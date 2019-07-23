//Считать с клавиатуры два целых числа и вывести большее из них.
//Если числа равны, вывести любое.

#include <stdio.h>

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    if ( a > b ) {
        printf("%d\n", a);
    } else {
        printf("%d\n", b);
    }
    
    return 0;
}
