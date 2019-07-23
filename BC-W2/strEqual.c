// int strEqual(char str1[], char str2[])

// Выяснить, равны ли строки.
#include <stdio.h>

int strEqual(char str1[], char str2[]) {
    for ( int index = 0; str1[index] == str2[index]; index++ ) {
        if ( str1[index] == '\0' ) {
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    char str1[] = {"olo"};
    char str2[] = {"ol"};
    
    printf("%d\n", strEqual(str1,str2));
    return 0;
}