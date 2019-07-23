// Вывести число Фибоначчи с заданным целым номером, по модулю не превышающим 46.

#include <stdio.h>

int main() {
    int num, result;
    int flag = 0;
    int fib1 = 1;
    int fib2 = 1;
    
    scanf("%d", &num);
    
    if ( num < 0 ) {
        num *= -1;
        
        if ( num % 2 == 0 ) {
            flag = 1;
        }
    }
    if ( num == 0 ) {
        fib2 = 0;
    }
    if ( num > 2 ) {
        for ( int i = 2; i < num; i++ ) {
            int fibSumm = fib1 + fib2;
            
            fib1 = fib2;
            fib2 = fibSumm;
        }
    }
    
    if ( flag == 1 ) {
        fib2 *= -1;
    }
    printf("%d\n", fib2);
    
    return 0;
}
