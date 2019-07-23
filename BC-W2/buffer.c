// buffer.c
#include <stdio.h>

#define QTY 100000000
#define BUFFER_SIZE 1000

void bufferPrint() {
    char symbol = 'a';
    char array[BUFFER_SIZE];
    int count = BUFFER_SIZE - 1;
    
    for ( int i = 0, j = 0; i < QTY; i++, j++, symbol++ ) {
        if ( count == j ) {
            array[j] = '\0';
            printf("%s", array);
            
            j = 0;
        }
        
        if (symbol > 'z') {
            symbol = 'a';
        }
        
        array[j] = symbol;
    }
    printf("\n");
}

void print() {
    char symbol = 'a';
    
    for ( int i = 0; i < QTY; i++, symbol++ ) {
        if ( symbol == '{') {
            symbol = 'a';
        }
        printf("%c", symbol);
    }
    printf("\n");
}

int main() {
    // bufferPrint();
    print();
    
    return 0;
}