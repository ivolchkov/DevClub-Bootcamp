// int average(int a, int b)
// Вернуть среднее арифметическое двух целых чисел. Использовать только тип int.
// Если среднее значение не является целым, то округлить его к ближайшему целому в сторону нуля.
#include <stdio.h>

int average(int a, int b) {
    if ( a > 0 && b < 0 ) {
        if ( a / 2 + b / 2 <= 17 && a / 2 + b / 2 > 0 ) {
            return a / 2 + b / 2 + (a % 2 + b % 2) / 2 - 1;
        }
        if ( a / 2 + b / 2 >= -17 && a / 2 + b / 2 < 0 ) {
            return a / 2 + b / 2 + (a % 2 + b % 2) / 2 + 1;
        }
    }
    if ( a < 0 && b > 0 ) {
        if ( a / 2 + b / 2 <= 17 && a / 2 + b / 2 > 0 ) {
            return a / 2 + b / 2 + (a % 2 + b % 2) / 2 - 1;
        }
        if ( a / 2 + b / 2 >= -17 && a / 2 + b / 2 < 0 ) {
            return a / 2 + b / 2 + (a % 2 + b % 2) / 2 + 1;
        }
    }
    return a / 2 + b / 2 + (a % 2 + b % 2) / 2;
}

int main() {
    int num1, num2;
    
    scanf("%d %d", &num1, &num2);
    
    int average1 = average(num1, num2);
    
    printf("%d\n", average1); 
    return 0;
}