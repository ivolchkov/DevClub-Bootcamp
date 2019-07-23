// void matrixRotate90(int target[SIZE][SIZE], int source[SIZE][SIZE], int size);

// Поворот матрицы на 90 градусов по часовой стрелке.
#include <stdio.h>
#define SIZE 3


void matrixRotate90(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0, limit = size - 1; row < size; row++, limit-- ) {
        for ( int col = 0; col < size; col++ ) {
            target[row][col] = source[col][limit];
        }
    }
}

// void matrixRotate270(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
//     for ( int row = 0, limit = size - 1; row < size; row++, limit-- ) {
//         for ( int col = 0; col < size; col++ ) {
//             target[col][row] = source[limit][col];
//         }
//     }
// }

// void matrixRotate180(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
//     for ( int row = 0, limit = size - 1; row < size; row++, limit-- ) {
//         for ( int col = 0, last = size - 1; col < size; col++, last-- ) {
//             target[col][row] = source[last][limit];
//         }
//     }
// }

int main() {
    int size = 3;
    int matrix[SIZE][SIZE];
    int target[SIZE][SIZE];
    int limit = size - 1;
    for ( int row = 0; row <= limit; row++) {
        for ( int col = 0; col <= limit; col++ ) {
           scanf("%d", &matrix[col][row]);
        }
    }

    matrixRotate180(target, matrix,size);
    printf("\n");
    for ( int row = 0; row <= limit; row++ ) {
        for ( int col = 0; col <= limit; col++ ) {
           printf("%d ", target[col][row]);
        }
        printf("\n");
    }
}