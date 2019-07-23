// Написать функцию:
// void arrayShiftRight(int array[], int size)
// Реализовать циклический сдвиг массива на 1 элемент вправо.
// Использование дополнительного массива не разрешается.
#include <stdio.h>

void arrayShiftRight(int array[], int size) {
    int last = size - 1;
    int temp = array[last];
    
    for ( int i = last; i > 0; i-- ) {
        array[i] = array[i-1];
    }
    array[0] = temp;
}


int main(int argc, char const *argv[])
{
    int size = 5;
    int array[size];
    
    array[0] = 5;
    array[1] = 6;
    array[2] = 3;
    array[3] = 8;
    array[4] = 9;
    arrayShiftRight(array,size);
    
    printf("%d\n",array[0] );
    return 0;
}