// void matrixRotate180(int target[SIZE][SIZE], int source[SIZE][SIZE], int size);

// Поворот матрицы на 180 градусов по часовой стрелке.
void matrixRotate180(int target[SIZE][SIZE], int source[SIZE][SIZE], int size) {
    for ( int row = 0, limit = size - 1; row < size; row++, limit-- ) {
        for ( int col = 0, last = size - 1; col < size; col++, last-- ) {
            target[col][row] = source[last][limit];
        }
    }
}