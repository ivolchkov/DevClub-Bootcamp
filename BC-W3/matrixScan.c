// void matrixScan(FILE *in, int matrix[SIZE][SIZE], int size);
// Столбец – первый индекс, строка – второй.

void matrixScan(FILE *in, int matrix[SIZE][SIZE], int size) {
    for ( int row = 0; row < size; row++ ) {
        for ( int col = 0; col < size; col++ ) {
            fscanf(in, "%d", &matrix[col][row]);
        }
    }
}
