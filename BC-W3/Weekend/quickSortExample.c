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
int partition(int array[], int lo, int hi ) {
    int mid = (lo + hi) / 2;
    int temp = array[mid];
    int tail = lo;
    
    array[mid] = array[hi];
    array[hi] = temp;
    
    for ( ; array[tail] < array[hi]; tail++ );
    for ( int i = tail + 1; i < hi ; i++ ) {
        if ( array[i] < array[hi]) {
            temp = array[i];
            array[i] = array[tail];
            array[tail] = temp;
            tail += 1;
        }
    }
    
    temp = array[tail];
    array[tail] = array[hi];
    array[hi] = temp;
    // arrayPrint(array, hi-lo);
    printf("%d\n", tail);
    return tail;
    
}

void quickSort(int array[], int lo, int hi) {
    if ( hi > lo ) {
        int pivot = partition(array, lo , hi);
        
        quickSort(array, lo, pivot - 1);
        quickSort(array, pivot + 1, hi);
        
    }
}


int main() {
    int size = 7;
    int array[size];
    
    arrScan(array, size);
    quickSort(array , 0, size-1);
    printf("\n");
    arrayPrint(array, size);
    
    return 0;
}
