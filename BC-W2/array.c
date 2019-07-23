// Считать в массив последовательность чисел длиной 10 из файла task.in.
// Записать его через пробел в файл task.out.

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 10;
    int array[size];
    
    for ( int i = 1; i < size; i++ ) {
        fscanf(in, "%d", &array[i]);
        fprintf(out, "%d ", array[i]);
    }
    fscanf(in, "%d", &array[size]);
    fprintf(out, "%d\n", array[size]);
    fclose(in);
    fclose(out);
    
    return 0;
}
