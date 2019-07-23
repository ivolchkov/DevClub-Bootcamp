// Вывести количество различных битовых последовательностей заданной длины (не более 32), не имеющих единиц, стоящих ближе, чем на заданном расстоянии.
// Расстояние считается равным 1, когда единицы стоят в соседних разрядах.

#include <stdio.h>

double bitSequences(int len) {
    if ( len == 0 ) {
        return 0;
    }
    if ( len > 0 ) {
        if ( len == 1 ) {
            return 1;
        }
        return bitSequences(len-1) + bitSequences(len-2);
    }
    
    if ( len == -1 ) {
        return 1;
    }
    return bitSequences(len+2) - bitSequences(len+1);
}

int main() {
    int len, distance;
    double pow = 1;
    int iterations;
    double source = 1;
    
    scanf("%d %d", &len, &distance);
    
    if ( distance > 1 ) {
        iterations = len - 2;
        
        for ( int i = 1; i < iterations ; pow *= 2, i++ );
        len += 2;
        source = bitSequences(len);
        if ( pow > source ) {
            for ( ; pow > source; pow/= 2 );
        }
        for ( int i = 2; i < distance; source -= pow, pow /= 2, i++ ) {
            if ( pow > source ) {
                for ( ; pow > source; pow/= 2 );
            }
        }
    } else {
        for ( int i = 0; i < len ; source *= 2, i++ );
    }
    printf("%.0f\n", source);
    
    return 0;
}
