// Написать функцию:
// void sliceReverse(int array[], int lo, int hi)
// Осуществить реверс части массива от lo до hi включительно.

void sliceReverse(int array[], int lo, int hi) {
    for ( ; hi > lo; lo++, hi-- ) {
        int temp = array[lo];
        
        array[lo] = array[hi];
        array[hi] = temp;
    }
}
