// Написать функцию 
// void arrayExchange(int array[], int len)

// Попарно обменять местами все четные элементы массива с нечетными, начиная с нулевого.
// a[0] <-> a[1]   a[2] <-> a[3]   .....
// Если последний элемент не имеет пары — не менять его значение.

// Запрещено использование дополнительного массива.

void arrayExchange(int array[], int len) {
    for ( int even = 0, odd = 1; odd < len; even += 2, odd += 2 ) {
        int temp = array[even];
        
        array[even] = array[odd];
        array[odd] = temp;
    }
}
