#include <stdio.h>

int main() {
    char a;
    
    for ( ;scanf("%c", &a) == 1 ; ) {
        printf("%c", a-32);
    }
    return 0;
}
