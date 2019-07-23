#include <stdio.h>

void strLowerCase(char str[]) {
    for ( int index = 0, buffer = str[index]; buffer != '\0'; buffer = str[index] ) {
        if ( buffer >= 'A' && buffer <= 'Z' ) {
            buffer += 'a' - 'A';
            str[index] = buffer;
        }
        index += 1;
    }
}

int main(int argc, char const *argv[])
{
    char str[100] = {"HeLLO123"};
    // char substract = 'H';
    strLowerCase(str);
    // int substract = 'A' - 'a';
    // printf("%d\n", substract);
    // printf("%s\n", str);
    return 0;
}

