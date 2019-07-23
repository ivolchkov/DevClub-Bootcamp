// Написать функцию:
// void arrayReverse(int array[], int size)

// Использование дополнительного массива не разрешается.

#include <stdio.h>

void arrayReverse(int array[], int size) {
    for ( int i = 0, last = size - 1; last > i; i++, last-- ) {
        size = array[i];
        array[i] = array[last];
        array[last] = size;
    }
}

// int main() {
//     int size = 5;
//     int array[size];
    
//     for ( int i = 0; i < size; i++) {
//         scanf("%d", &array[i]);
//     }
    
//     int last = size - 1;
    
//     for ( int i = 0, j = last; j > i; i++, j-- ) {
//         int bin;
        
//         bin = array[i];
//         array[i] = array[j];
//         array[j] = bin;
//     }
    
//     for ( int i = 0; i < size; i++) {
//         printf("%d ", array[i]);
//     }
    
//     return 0;
// }
