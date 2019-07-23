// Написать функцию:
// arrayShiftLeft(int array[], int size)
// Реализовать циклический сдвиг массива на 1 элемент влево.
// Использование дополнительного массива не разрешается.
#include <stdio.h>

void arrayShiftLeft(int array[], int size) {
    int temp = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        array[i-1] = array[i];
    }
    array[size-1] = temp;
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
    arrayShiftLeft(array,size);
    
    for (int i = 0; i < size; i++)
    {
        printf("%d\n",array[i] );
    }
    
    return 0;
}