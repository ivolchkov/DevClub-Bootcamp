// Вывести количество различных битовых последовательностей заданной длины (не более 32), не содержащих двух единиц подряд.
#include <stdio.h>

int maxPow(int len) {
    int base2 = 1;
    
    for ( int i = 1; i < len; base2 *= 2, i++ );
    
    return base2;
}

int bitSequences(int maxValue, int len, int count) {
    int flag = 1;
    int maxPower = maxPow(len);
    int arr[len];
    int base = 2;
    int num = maxValue;
    
    if ( maxValue < 0 ) {
        return count;
    }
    
    for ( int i = 0; maxPower > 0; maxPower /= base, i++ ) {
        int result = num / maxPower;
        
        if ( result != 0 ) {
            num %= maxPower;
        }
        arr[i] = result;
        printf("%d ",result );
    }
    printf("\n");
    for ( int i = 1; i < len; i++ ) {
        if ( arr[i] == 1 && arr[i-1] == 1 ) {
            flag = 0;
        }
    }
    if ( flag ) {
        count += 1;
    }
    
    return bitSequences(maxValue-1, len, count);
}

int main() {
    int len;
    int count = 0;
    int maxValue;
    
    scanf("%d", &len);
    
    maxValue = maxPow(len) * 2 - 1;
    
    printf("%d\n", bitSequences(maxValue, len, count));
    
    return 0;
}
