// Вывести N-ное по счёту простое число (см. Википедию).
// N считать с клавиатуры.
// Оптимизировать работу программы, насколько это возможно.
// В случае неопределенности ответа вывести -1.

#include <stdio.h>

int isPrime(int n) {
    for ( int i = 2; i < n / 2; i++ ) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int number, max;
    int flag = 1;
    
    scanf("%d", &number);
    if ( number >= 1 ) {
        for ( int i = 2, count = 0; count < number; i++ ) {
            flag = isPrime(i);
            if ( flag ) {
                count += 1;
                max = i;
            }
        }
        printf("%d\n", max);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
