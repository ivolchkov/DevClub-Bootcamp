#include <stdio.h>

int maxPow(int len) {
    int base2 = 1;
    
    for ( int i = 0; i < len; base2 *= 2, i++ );
    
    return base2;
}

int valueReturn(int bit, int distance) {
    if ( distance == 0 ) {
        return 1;
    } else if ( bit == distance ) {
        return 1;
    } else {
        return valueReturn(bit-1, distance) + valueReturn(bit-1, distance-1);
    }
}

int main() {
    int base, bit, distance;
    int maxPower;
    int hammingLenght;
    
    scanf("%d %d %d", &base, &bit, &distance);
    
    maxPower = maxPow(bit);
    if ( base < maxPower ) {
        hammingLenght = valueReturn(bit, distance);
        printf("%d\n", hammingLenght);
    }
    
    return 0;
}
