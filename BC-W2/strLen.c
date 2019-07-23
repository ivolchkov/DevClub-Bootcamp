// int strLen(char str[])

// Подсчитать длину заданной строки.
#include <stdio.h>

int strLen(char str[]) {
    int len = 0;
    
    for ( ; str[len] != '\0'; len++ );
    return len;
}

int main(int argc, char const *argv[])
{
    char str[] = {"Hello, it`s Bender"};
    
    printf("%d\n", strLen(str));
    return 0;
}