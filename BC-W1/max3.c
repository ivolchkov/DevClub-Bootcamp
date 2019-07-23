//Считать с клавиатуры три целых чисел и вывести большее из них.
//В случае равенства выводить любое.
//Данная задача решается без массивов, циклов и функций.
#include <stdio.h>

int main() {
    int a, b, c;
    int max;
    
    scanf("%d %d %d", &a, &b, &c);
    
    max = a;
    if ( max < b ) {
        max = b;
    }
    if ( max < c ) {
        max = c;
    }
    
    printf("%d\n", max);
    
    return 0;
}
