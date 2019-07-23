// Написать функцию:
// int arraySum(int array[], int size)
// Вернуть сумму элементов массива.
// size > 0

int arrayMax(int array[], int size) {
    int sum = array[0];
    
    for ( int i = 1; i < size; i++ ) {
        sum += array[i];
    }
    return sum;
}
