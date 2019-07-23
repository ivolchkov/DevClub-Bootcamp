// void merge(int array[], int lo, int mid, int hi)
// Слияние двух сортированных подмассивов в один отсортированный подмассив.
// Первый подмассив от lo до mid не включая mid
// Второй подмассив от mid до hi не включая hi
#include <stdio.h>

void arrPrint(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
           printf("%d ", array[i]);
        }
        printf("\n");
}

void arrScan(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
           scanf("%d", &array[i]);
        }
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

int main() {
    int size = 7;
    int array[size];
    
    arrScan(array,size);
    merge(array,0,3,7);
    arrPrint(array,size);
    return 0;
    
}