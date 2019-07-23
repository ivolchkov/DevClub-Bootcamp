#include <stdio.h>

unsigned int bitSequences(int len) {
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
    unsigned int pow = 1;
    int iterations;
    unsigned int source = 1;
    double sourceMax = 1;
    int minLimit;
    
    scanf("%d %d", &len, &distance);
    
    minLimit = len + 1;
    if ( distance > 1 ) {
        iterations = len - 2;
        
        for ( int i = 1; i < iterations; pow *= 2, i++ );
        len += 2;
        source = bitSequences(len);
        if ( pow > source ) {
            for ( ; pow > source; pow /= 2 );
        }
        
        for ( int i = 2; i < distance; source -= pow, pow /= 2, i++ ) {
            if ( pow > source ) {
                for ( ; pow > source; pow /= 2 );
            }
            if ( source - pow < minLimit ) {
                for ( ; source - pow < minLimit; pow /= 2 );
            }
        }
        printf("%d\n", source);
    } else if ( distance == 1 ) {
        for ( int i = 0; i < len; sourceMax *= 2, i++ );
        printf("%.0f\n", sourceMax);
    }
    
    return 0;
}
