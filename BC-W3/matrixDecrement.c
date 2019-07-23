void matrixDecrement(int matrix[SIZE][SIZE], int decrement[SIZE][SIZE], int size) {
    for ( int i = 0; i < size; i++ ) {
        for ( int j = 0; j < size; j++ ) {
            matrix[j][i] -= decrement[j][i];
        }
    }
}
