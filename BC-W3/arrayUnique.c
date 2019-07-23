
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


int arrayUnique(int array[], int size) {
    int current = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        for ( int j = i; j < size; j++ ) {
            if ( current == array[j] ) {
                for ( int k = j + 1; k < size; k++ ) {
                    array[k-1] = array[k];
                }
                j -= 1;
                size -= 1;
            }
        }
        current = array[i];
    }
    return size;
}

int main() {
    int size = 7;
    int array[size];
    
    arrScan(array,size);
    int result = arrayUnique(array,size);
    arrPrint(array,result);
    printf("%d\n", result);
    
    return 0;
    
}
