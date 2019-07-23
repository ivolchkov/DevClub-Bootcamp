void insertSort(int array[], int size) {
    for ( int i = 1; i <= size; i++ ) {
        int temp = array[i];
        int j = i;
        
        for ( int prev = j - 1; j > 0 && array[prev] > temp; j--, prev-- ) {
            array[j] = array[prev];
        }
        array[j] = temp;
    }
}
