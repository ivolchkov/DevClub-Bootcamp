//Считать с клавиатуры количество дней. Если эта величина равна 366 вывести «yes», если величина равна 365 вывести «no». В других случаях вывести «Invalid param».

#include <stdio.h>

int main() {
    int days;
    
    scanf("%d", &days);
    
    if ( days == 366 ) {
        printf("yes\n");
    } else if ( days == 365 ) {
      printf("no\n");  
    } else {
        printf("Invalid param\n");
    }
    
    return 0;
}
