#include <stdio.h>

void arrayShift(int array[], int size, int shift) {
    int part;
    
    shift %= size;
    if ( shift < 0 ) {
        shift += size;
    }
    part = size - shift;
    if ( shift < part ) {
        int arrayTemp[shift];
        
        for ( int i = part, j = 0; i < size; i++, j++ ) {
            arrayTemp[j] = array[i];
        }
        for ( int i = size - 1, j = i - shift; i >= shift; i--, j-- ) {
            array[i] = array[j];
        }
        for ( int i = 0; i < shift; i++ ) {
            array[i] = arrayTemp[i];
        }
    } else {
        int arrayTemp[part];
        
        for ( int i = 0; i < part; i++ ) {
            arrayTemp[i] = array[i];
        }
        
        for ( int i = 0, j = part; i < shift; i++, j++ ) {
            array[i] = array[j];
        }
        for ( int i = shift, j = 0; i < size; i++, j++ ) {
            array[i] = arrayTemp[j];
        }
    }
}

void arrScan(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
           scanf("%d", &array[i]);
        }
}

void arrPrint(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
           printf("%d ", array[i]);
        }
        printf("\n");
}


int main() {
    int size = 7;
    int array[size];
    int shift = -4;

    
    arrScan(array,size);
    arrayShift(array, size, -10256); 
    arrPrint(array,size);

    return 0;
}
