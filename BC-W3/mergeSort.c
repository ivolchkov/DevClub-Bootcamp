// В файле task.in дано число len и массив размером len элементов.
// Отсортировать элементы в порядке неубывания.
// Использовать алгоритм mergeSort.
// Результат записать в task.out
// Допустимо использование рекурсии.

#include <stdio.h>

void arrPrint(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int sizeScan(FILE *in) {
    int len;
    
    fscanf(in, "%d", &len);
    
    return len;
}

void arrScan(FILE *in, int array[], int size) {
    for ( int i = 0; i < size && fscanf(in, "%d", &array[i]) == 1; i++ );
}

void merge(int array[], int lo, int mid, int hi) {
    int size = hi - lo;
    int buffer[size];
    int i, j, k;
    
    for ( i = lo, j = mid, k = 0; i < mid && j < hi; k++ ) {
        if ( array[i] <= array[j] ) {
            buffer[k] = array[i];
            i += 1;
        } else {
            buffer[k] = array[j];
            j += 1;
        }
    }
    
    for ( ; i < mid; i++, k++ ) {
        buffer[k] = array[i];
    }
    
    for ( ; j < hi; j++, k++ ) {
        buffer[k] = array[j];
    }
    
    for ( int i = lo, k = 0; i < hi; i++, k++ ) {
        array[i] = buffer[k];
    }
}

void mergeSort(int array[], int lo, int hi) {
    int mid = (lo + hi) / 2;
    
    if ( mid == lo ) {
        return;
    }
    mergeSort(array, lo, mid);
    mergeSort(array, mid, hi);
    merge(array, lo, mid, hi);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = sizeScan(in);
    int array[size];
    
    arrScan(in, array, size);
    fclose(in);
    
    mergeSort(array, 0, size);
    
    arrPrint(out, array, size);
    fclose(out);
    
    return 0;
}
