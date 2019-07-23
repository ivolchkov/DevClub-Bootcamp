#include <stdio.h>
#include<stdlib.h>

#define SIZE 100

int main(){
    int *array;
    
    array = (int*)malloc(sizeof(int) * SIZE);
    
    for( int i = 0; i < SIZE; i++ ) {
        int *newArray = (int*)malloc(sizeof(int) * SIZE);
    }
    
    free(array);
    array = NULL;
    return 0;
}