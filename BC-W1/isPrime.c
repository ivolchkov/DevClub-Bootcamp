// Написать функцию:
// int isPrime(int n)
// Проверить, является ли данное число простым.

int isPrime(int n) {
    if ( n <= 1 ) {
        return 0;
    }
    for ( int i = 2; i < n; i++ ) {
        if ( n % i == 0 ) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int number, value;
    
    scanf("%d", &number);
    
    value = isPrime(number);
    printf("%d\n", value);
}