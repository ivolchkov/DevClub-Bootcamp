// В файле task.in дана длина последовательности чисел (число больше нуля) и сама последовательность.
// Прочитать последовательность в массив.
// Найти все отрицательные числа и заменить их положительными, равными по модулю.
// Результирующий массив вывести в task.out.
#include <stdio.h>

int arrSize(FILE *in) {
    int size;
    
    fscanf(in, "%d", &size);
    return size;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = arrSize(in);
    int array[size];
    
    for ( int i = 0; i < size - 1; i++ ) {
        fscanf(in, "%d", &array[i]);
        
        if ( array[i] < 0 ) {
            array[i] = -array[i];
        }
        
        fprintf(out, "%d ", array[i]);
    }
    fscanf(in, "%d", &array[size]);
    if ( array[size] < 0 ) {
        array[size] = -array[size];
    }
    fprintf(out, "%d\n", array[size]);
    
    fclose(in);
    fclose(out);
    
    return 0;
}
