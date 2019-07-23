// Кузнечик начинает свой путь на клетке 0 и может прыгать на расстояние от 1 до <maxJump> клеток. Прыжки возможны только на целое число клеток вперед.
// Посчитать кол-во способов <ways>, которыми кузнечик может попасть на клетку <cell>.

// В файле task.in заданы целые числа:
// <maxJump> <cell>

// Вывести ways в task.out.

// Ограничения:
// 1 <= maxJump <= 100
// 1 <= cell <= 100
// 1 <= ways <= 999 999 999 999 999 99

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int maxJump, cell;
    int size = 100;
    unsigned long long ways;
    unsigned long long array[size];
    unsigned long long maxPow = 1;
    int i = 0;
    
    fscanf(in, "%d %d", &maxJump, &cell);
    fclose(in);
    
    for ( ; i < maxJump && i < cell; i++, maxPow <<= 1 ) {
        array[i] = maxPow;
    }
    ways = array[i-1];
    for ( i = maxJump; i < cell; i++ ) {
        array[i] = 0;
        for ( int j = i - 1; j >= i - maxJump; j-- ) {
            array[i] += array[j];
        }
        ways = array[i];
    }
    fprintf(out, "%lld\n", ways);
    fclose(out);
    
    return 0;
}
