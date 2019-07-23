// Написать функцию:
// void strRot13(char str[])
// Зашифровать строку по алгоритму ROT13

#include <stdio.h>

void strRot13(char str[]) {
    for ( int index = 0, buffer = str[index]; buffer != '\0'; buffer = str[index] ) {
        if ( buffer >= 'A' && buffer <= 'Z' ) {
            if ( buffer >= 'A' && buffer <= 'M' ) {
                buffer += 'n' - 'a';
            } else {
                buffer -= 'n' - 'a';
            }
            str[index] = buffer;
        }
        if ( buffer >= 'a' && buffer <= 'z' ) {
            if ( buffer >= 'a' && buffer <= 'm' ) {
                buffer += 'n' - 'a';
            } else {
                buffer -= 'n' - 'a';
            }
            str[index] = buffer;
        }
        index += 1;
    }
}

int main(int argc, char const *argv[])
{
    char str[100] = {"BalKHello"};
    // // char substract = 'H';
    strRot13(str);
    // int substract = 'N' - 'A';
    // printf("%d\n", substract);
    // printf("%s\n", str);
    return 0;
}

