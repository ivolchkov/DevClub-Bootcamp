// В файле task.in дано число len и массив размером len элементов.
// Отсортировать элементы в порядке неубывания.
// Использовать алгоритм quickSort.
// Результат записать в task.out

#include <stdio.h>

int scanLen(FILE *in) {
    int len;
    
    fscanf(in, "%d", &len);
    
    return len;
}

void arrScan(FILE *in, int array[], int size) {
    for ( int i = 0; i < size && fscanf(in, "%d", &array[i]) == 1; i++ );
}

void arrPrint(FILE *out, int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        fprintf(out, "%d ", array[i]);
    }
    fprintf(out, "%d\n", array[last]);
}

int partition(int array[], int start, int end) {
    int mid = (start + end) / 2;
    int tail = start;
    int temp = array[mid];
    
    array[mid] = array[end];
    array[end] = temp;
    for ( int i = start; array[end] > array[i]; tail++, i++ );
    
    for ( int i = tail + 1; i < end; i++ ) {
        if ( array[end] > array[i] ) {
            temp = array[i];
            
            array[i] = array[tail];
            array[tail] = temp;
            tail += 1;
        }
    }
    temp = array[tail];
    array[tail] = array[end];
    array[end] = temp;
    
    return tail;
}

void quickSort(int array[], int start, int end) {
    if ( end > start ) {
        int pivot = partition(array, start, end);
        
        quickSort(array, start, pivot-1);
        quickSort(array, pivot+1, end);
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = scanLen(in);
    int array[size];
    
    arrScan(in, array, size);
    fclose(in);
    
    quickSort(array, 0, size-1);
    
    arrPrint(out, array, size);
    fclose(out);
    
    return 0;
}
