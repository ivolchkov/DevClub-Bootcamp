#include <stdio.h>

void insertionSort(int array[], int size) {
    for ( int i = 1; i < size; i++ ) {
        int j = i;
        int temp = array[i];
        
        for ( int prev = j - 1; j > 0 && temp < array[prev]; j--, prev-- ) {
            array[j] = array[prev];
        }
        array[j] = temp;
    }
}

void selectionSort(int array[], int size ) {
    for ( int i = 0; i < size; i++ ) {
        int min = i;
        int limit = size - 1;
        
        for ( int j = limit; j > i && array[j] < array[min] ; j-- ) {
            min = j;
        }
        
        if ( min != i ) {
            int temp = array[i];
            
            array[i] = array[min];
            array[min] = temp;
        }
    }
}

int main() {
    int array[5] = {7,2,6,1,2};

    
    selectionSort(array, 5);
    
    for ( int i = 0; i < 5; i++ ) {
        printf("%d ", array[i]);
    }
    return 0;
}