// void matrixRotate180(int target[SIZE][SIZE], int source[SIZE][SIZE], int size);

// Поворот матрицы на 270 градусов по часовой стрелке.
void matrixRotate270(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0, limit = size - 1; row < size; row++, limit-- ) {
        for ( int col = 0; col < size; col++ ) {
            target[col][row] = source[limit][col];
        }
    }
}