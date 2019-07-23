// Вывести числовую пирамидку на total строк. Порядок строк – обратный.
// В первой строке стоит число 1. В последующих строках стоят увеличивающиеся числа через пробел.

#include <stdio.h>

int first_number(int n) {
    if ( n == 2 ) {
        return 3;
    }
    return first_number(n-1) + n;
}

int main() {
    int amount, count, firstNum, lastNum;
    
    scanf("%d", &amount);
    count = amount;
    for ( int i = 0; i < amount - 1; i++ ) {
        firstNum = first_number(count) - (count - 1);
        lastNum = first_number(count);
        for ( int j = firstNum; j < lastNum; j++ ) {
            printf("%d ", j);
        }
        printf("%d\n", lastNum);
        count -= 1;
    }
    printf("1\n");
    
    return 0;
}
