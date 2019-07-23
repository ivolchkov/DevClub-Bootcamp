// Расстояние Хэмминга — число позиций, в которых соответствующие цифры двух двоичных слов одинаковой длины различны.
// Пример: d(00100111, 10100100) = 3, так как различаются старший бит и два младших.

// Считать числа base, bits, distance.
// 0 <= base < 2^bits
// 1 <= bits < 30
// 0 <= distance <= bits

// Вывести количество чисел длиной не более bits бит, расстояние Хэмминга между которыми и числом base равно distance.

#include <stdio.h>

int maxPow(int len) {
    int base2 = 1;
    
    for ( int i = 1; i < len; base2 *= 2, i++ );
    
    return base2;
}

int main() {
    int base, bit, distance;
    int maxValue, maxPower;
    int size = 6;
    int arrBase[size];
    int amount = 0;
    
    scanf("%d %d %d", &base, &bit, &distance);
    
    maxValue = 2 * maxPow(bit);
    maxPower = maxPow(bit);
    arrBase[size] = arrBase[bit];
    for ( int i = 0; maxPower > 0; maxPower /= 2, i++ ) {
        int result = base / maxPower;
        
        if ( result != 0 ) {
            base %= maxPower;
        }
        arrBase[i] = result;
    }
    for ( int i = 0; i < maxValue; i++ ) {
        int count = 0;
        
        maxPower = maxPow(bit);
        for ( int j = 0, num = i; maxPower > 0; j++, maxPower /= 2 ) {
            int result = num / maxPower;
            
            if ( result != 0 ) {
                num %= maxPower;
            }
            if ( arrBase[j] != result ) {
                count += 1;
            }
        }
        if ( count == distance ) {
            amount += 1;
        }
    }
    
    printf("%d\n", amount);
    
    return 0;
}
