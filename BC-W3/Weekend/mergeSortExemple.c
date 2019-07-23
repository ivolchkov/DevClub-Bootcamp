#include <stdio.h>

void arrayPrint( int array[], int size) {
    int last = size - 1;
    
    for ( int i = 0; i < last; i++ ) {
        printf( "%d ", array[i]);    
    } 
    printf( "%d\n", array[last]);
}

void merge(int array[], int lo, int mid, int hi) {
    int temp[hi - lo];
    int i = lo;
    int j = mid;
    int k = 0;
    
    for ( ; i < mid && j < hi; k++ ) {
        if ( array[i] <= array[j] ) {
            temp[k] = array[i];
            i += 1;
        } else {
            temp[k] = array[j];
            j += 1;
        }
    }
    
    for ( ; i < mid; i++, k++ ) {
        temp[k] = array[i];
    }
    
    for ( ; j < hi; j++, k++ ) {
        temp[k] = array[j];
    }
    
    for ( int i = lo, k = 0; i < hi; i++, k++ ) {
        array[i] = temp[k];
    }
}

void mergeSort(int array[], int lo, int hi) {
    int mid = (lo + hi) / 2;
    
    if ( mid == lo ) {
        return;
    }
    
    mergeSort(array, lo, mid);
    mergeSort(array, mid, hi);
    
    merge( array, lo, mid, hi);
}

int main() {
    int size = 15;
    int array[] = {7, 45, 37, 91, 23, 88, 15, 5, 62, 42, 99, 100, 3, 5, 19};
    
    arrayPrint(array, size);
    mergeSort(array , 0, size);
    arrayPrint(array, size);
    
    
    return 0;
}
