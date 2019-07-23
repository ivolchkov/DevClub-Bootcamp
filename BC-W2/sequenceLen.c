// Считать из файла task.in последовательность чисел размером не более 100 элементов.
// Посчитать длину последовательности и вывести ее в task.out.

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int count = 0;
    int maxSize = 100;
    int array[maxSize];
    
    for ( ; count < maxSize && fscanf(in, "%d", &array[count]) == 1; count++ );
    fclose(in);
    
    fprintf(out, "%d\n", count);
    fclose(out);
    
    return 0;
}
