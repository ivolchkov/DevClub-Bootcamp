// int partition(int array[], int start, int end)

// В качестве опорного элемента брать среднее арифметическое между start и end с округлением вниз.

#include <stdio.h>

void arrayPrint( int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        printf( "%d ", array[i]);    
    } 
    printf( "%d\n", array[last]);
}
void arrScan(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
           scanf("%d", &array[i]);
        }
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

int main() {
    int size = 10;
    int array[size];
    
    arrScan(array, size);
    partition(array , 2, 7);
    printf("\n");
    arrayPrint(array, size);
    
    return 0;
}
