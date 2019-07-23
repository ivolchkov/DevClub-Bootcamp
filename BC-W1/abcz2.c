// Считать с клавиатуры целое число.
// - Если число четное, вывести alpha
// - Если число кратно трем, вывести bravo
// - Если число кратно пяти, вывести charlie
// - Если число не кратно ни одному из них, вывести zulu

#include <stdio.h>

int main() {
    int a;
    int isZulu = 1;
    
    scanf("%d", &a);
    
    if ( a % 2 == 0 ) {
        printf("alpha\n");
        isZulu = 0;
    }
    if ( a % 3 == 0 ) {
        printf("bravo\n");
        isZulu = 0;
    }
    if ( a % 5 == 0 ) {
        printf("charlie\n");
        isZulu = 0;
    }
    if ( isZulu ) {
        printf("zulu\n");
    }
    
    return 0;
}
