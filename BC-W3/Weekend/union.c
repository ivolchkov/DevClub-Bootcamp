#include <stdio.h>

typedef enum {
    FIRST,
    SECOND = 100500,
    THIRD
} Num;

typedef union {
    int array[2];
    int *ptr;
} Data;

int main() {
    Data un;
    int source;
    
    
    un.ptr = &source;
    printf("%p\n", un.ptr);
    
    un.array[0] = 10;
    un.array[1] = 10;
    printf("%p\n", un.ptr);
    
    // printf("%d\n", THIRD);
    return 0;
}