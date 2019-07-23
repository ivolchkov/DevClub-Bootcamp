// В файле task.in дано искомое число needle, а также последовательность чисел размером не более 100 элементов.
// Найти needle в массиве и вывести в файл task.out его индекс либо -1, если число не найдено.

#include <stdio.h>

int needleScan(FILE *in) {
    int number;
    
    fscanf(in, "%d", &number);
    return number;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int number;
    int needle = needleScan(in);
    int index = -1;
    
    for ( int i = 0; fscanf(in, "%d", &number) == 1; i++ ) {
        if ( number == needle ) {
            index = i;
        }
    }
    fprintf(out, "%d\n", index);
    
    fclose(in);
    fclose(out);
    
    return 0;
}