// int factorial(int n)
// Использовать рекурсию.
// В случае неопределенности возвращать -1.

int factorial(int n) {
    if ( n <= 1 ) {
        if ( n >= 0 ) {
            return 1;
        }
        return -1;
    }
    return n * factorial(n-1);
}
