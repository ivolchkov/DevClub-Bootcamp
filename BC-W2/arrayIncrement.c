// void arrayIncrement(int array[], int size, int increment)
// Увеличить каждый элемент массива на значение increment.

void arrayIncrement(int array[], int size, int increment) {
    for ( int i = 0; i < size; i++ ) {
        array[i] += increment;
    }
}
