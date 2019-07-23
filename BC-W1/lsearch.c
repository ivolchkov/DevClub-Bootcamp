// В файле task.in дано искомое число needle, а также последовательность чисел размером не более 100 элементов.
// Найти needle в массиве и вывести в файл task.out его индекс либо -1, если число не найдено.

#include <stdio.h>


int arraySearch(FILE *in, int array[], int size, int needle ) {
    for ( int load = 0; load < size && fscanf(in, "%d", &array[i]) == 1; load++ ) {
        if ( needle == array[load] ) {
            return load;
        }
    }
    return -1;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 100;
    int array[size];
    int needle;
    
    fscanf(in, "%d", &needle);
    
    fprintf(out, "%d\n", arraySearch(in, array, size, needle));
    
    fclose(in);
    fclose(out);
    
    return 0;
}


