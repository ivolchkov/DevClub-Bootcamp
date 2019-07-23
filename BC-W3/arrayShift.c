// Написать функцию:
// void arrayShift(int array[], int size, int shift)
// Реализовать циклический сдвиг массива на shift элементов вправо. Максимизировать производительность при оптимальном использовании памяти.
// Требуемая сложность: O(N)
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


void arrayShift(int array[], int size, int shift) {
    int limit;
    
    shift %= size;
    if ( shift < 0 ) {
        shift *= -1;
        shift = size - shift;
    }
    limit = size - shift;
    if ( shift > limit ) {
        int temp[limit];
        
        for ( int i = 0; i < limit; i++ ) {
            temp[i] = array[i];
        }
        for ( int i = 0, last = limit; i <= shift; i++, last++ ) {
            array[i] = array[last];
        }
        for ( int i = 0, j = shift; j < size; i++, j++ ) {
            array[j] = temp[i];
        }
    } else {
        int temp[shift];
        
        for ( int i = limit, j = 0; j < shift; i++, j++ ) {
            temp[j] = array[i];
        }
        for ( int i = limit - 1, last = size - 1; last > shift; i--, last-- ) {
            array[last] = array[i];
        }
        for ( int i = 0; i < shift; i++ ) {
            array[i] = temp[i];
        }
    }
}

int main() {
    int size = 7;
    int array[size];
    int shift = 3;
    arrScan(array,size);
    arrayShift(array,size,shift);
    arrPrint(array,size);
    
    return 0;
    
}


// void arrayShift(int array[], int size, int shift) {
//     int limit;
    
//     shift %= size;
//     if ( shift < 0 ) {
//         shift += size;
//     }
//     limit = size - shift;
//     if ( shift < limit  ) {
//         int temp[shift];
        
//         for ( int i = limit, j = 0; j < shift; i++, j++ ) {
//             temp[j] = array[i];
//         }
//         for ( int last = size - 1, i = last - shift; last >= shift; i--, last-- ) {
//             array[last] = array[i];
//         }
//         for ( int i = 0; i < shift; i++ ) {
//             array[i] = temp[i];
//         }
//     } else {
//         int temp[limit];
        
//         for ( int i = 0; i < limit; i++ ) {
//             temp[i] = array[i];
//         }
//         for ( int i = 0, last = limit; i <= shift; i++, last++ ) {
//             array[i] = array[last];
//         }
//         for ( int i = 0, j = shift; j < size; i++, j++ ) {
//             array[j] = temp[i];
//         }
//     }
// }

void arrayShift(int array[], int size, int shift) {
    int limit;
    
    shift %= size;
    if ( shift < 0 ) {
        shift += size;
    }
    limit = size - shift;
    if ( shift < limit ) {
        int temp[shift];
        
        for ( int i = limit, j = 0; j < shift; i++, j++ ) {
            temp[j] = array[i];
        }
        for ( int last = size - 1, i = limit - 1; last >= shift; i--, last-- ) {
            array[last] = array[i];
        }
        for ( int i = 0; i < shift; i++ ) {
            array[i] = temp[i];
        }
    } else {
        int temp[limit];
        
        for ( int i = 0; i < limit; i++ ) {
            temp[i] = array[i];
        }
        for ( int i = 0, last = limit; i < shift; i++, last++ ) {
            array[i] = array[last];
        }
        for ( int i = 0, j = shift; j < size; i++, j++ ) {
            array[j] = temp[i];
        }
    }
}
