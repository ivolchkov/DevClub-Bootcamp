// Считать с клавиатуры 2 целых числа - номер телефона и количество минут.
// Стоимость минуты разговора составляет 1$ за звонок на городской номер и 40$ за звонок на короткий номер. За звонок по номерам специальных служб плата не взимается. В случае неопределенности вывести -1.

#include <stdio.h>

int main() {
    int phoneNumber, minutes, callCost;
    
    scanf("%d %d", &phoneNumber, &minutes);
    if ( phoneNumber > 999999 && phoneNumber < 10000000 ) {
        printf("%d$\n", minutes);
    } else if ( phoneNumber == 101 || phoneNumber == 102 || phoneNumber == 103 || phoneNumber == 104 || phoneNumber == 112 ) {
        printf("0$\n");
    } else if ( phoneNumber > 99 && phoneNumber < 1000 ) {
        callCost = 40;
        printf("%d$\n", minutes*callCost);
    } else {
        printf("-1\n");
    }
    
    return 0;
}



        