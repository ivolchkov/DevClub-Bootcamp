// Считать с клавиатуры целое число - дискриминант квадратного уравнения. Вывести на экран число разных корней этого уравнения

#include <stdio.h>

int main() {
    int discriminant;
    
    scanf("%d", &discriminant);
    
    if ( discriminant == 0 ) {
        printf("1\n");
    } else if ( discriminant > 0 ) {
        printf("2\n");
    } else {
        printf("0\n");
    }
    return 0;
}
