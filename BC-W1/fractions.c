// Вывести возрастающую последовательность всех несократимых дробей в промежутке от 0 до 1, знаменатель которых не превышает заданное число.
// Вводимое число не превышает 200

#include <stdio.h>

int main() {
    int number;
    
    scanf("%d", &number);
    printf("0/1 ");
    for ( int i = number; i >= 2; i-- ) {
        printf("1/%d ", i);
    }
    for ( int i = 2; i < number; i++ ) {
        printf("%d/%d ", i, i+1);
    }
    printf("1/1\n");
    
    return 0;
}
