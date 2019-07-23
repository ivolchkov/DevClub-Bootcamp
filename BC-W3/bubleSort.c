#include <stdio.h>
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

void bubbleSort(int array[], int size) {
    int isSorted = 0;
    int last = size - 1;
    
    for ( int i = 0; i < last && isSorted != 1; i++ ) {
        int limit = last - i;
        
        isSorted = 1;
        for ( int j = 0, next = j + 1; j < limit; j++, next++ ) {
            int temp = array[next];
            
            if ( array[j] > array[next] ) {
                array[next] = array[j];
                array[j] = temp;
                isSorted = 0;
            }
        }
    }
}

void insertSort(int array[], int size) {
    for ( int i = 1; i <= size; i++ ) {
        int temp = array[i];
        int j = i;
        
        for ( int prev = j - 1; j > 0 && array[prev] > temp; j--, prev-- ) {
            array[j] = array[prev];
        }
        array[j] = temp;
    }
}

void selectSort(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
        int temp = array[i];
        int min = i;
        
        for ( int j = i + 1; j < size; j++ ) {
            if ( array[j] < array[min] ) {
                min = j;
            }
        }
        if ( min != i ) {
            array[i] = array[min];
            array[min] = temp;
        }
    }
}


int main(int argc, char const *argv[])
{
    int size = 5;
    int array[size];
    
    arrScan(array,size);
    selectSort(array,size);
    arrPrint(array,size);
    return 0;
}