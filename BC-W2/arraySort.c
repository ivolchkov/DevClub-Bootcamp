// Написать функцию:
// void arraySort(int array[], int size)
// Отсортировать элементы в порядке неубывания.
// Настоятельно рекомендуется разработать алгоритм самостоятельно, без помощи гугла.

#include <stdio.h>

void arraySort(int array[], int size) {
    int flag = 0;
    
    for ( int i = 0, last = size - 1; i < last && flag != 1; i++ ) {
        flag = 1;
        for ( int j = 0; j < size; j++ ) {
            if ( array[j] > array[j+1] ) {
                int temp = array[j];
                
                array[j] = array[j+1];
                array[j+1] = temp;
                flag = 0;
            }
        }
    }
}


int main () {
    int size = 5;
    int array[size];
    
    for (int i = 0; i < size; i++ ) 
    {
        scanf("%d", &array[i]);
    }
    
    arraySort(array,size);
    
    for (int i = 0; i < size; i++ ) 
    {
        printf("%d ", array[i]);
    }
}


