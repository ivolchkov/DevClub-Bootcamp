// Считать с клавиатуры положительную длину числовой последовательности и саму последовательность.
//  Проверить, упорядочена ли последовательность по неубыванию. Если упорядочена вывести на экран «yes», в противном случае вывести «no».

#include <stdio.h>

int main() {
    int lenght, min, num;
    int check = 0;
    
    scanf("%d", &lenght);
    scanf("%d", &min);
    
    for ( int i = 1; i < lenght; i++ ) {
        scanf("%d", &num);
        if ( min > num ) {
            check = 1;
        }
        min = num;
    }
    if ( check == 0 ) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    
    return 0;
}

