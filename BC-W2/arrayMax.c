// Написать функцию:
// int arrayMax(int array[], int size)
// Вернуть значение максимального элемента в массиве.

int arrayMax(int array[], int size) {
    int arrMax = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        if ( array[i] > arrayMax ) {
            arrayMax = array[i];
        }
    }
    return arrayMax;
}
