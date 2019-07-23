// Вывести количество различных битовых последовательностей заданной длины (не более 32), не имеющих единиц, стоящих ближе, чем на заданном расстоянии.
// Расстояние считается равным 1, когда единицы стоят в соседних разрядах.

#include <stdio.h>

unsigned int maxPow(int len) {
    unsigned int baseN = 1;
    
    for ( int i = 1; i < len; baseN *= 2, i++ );
    return baseN;
}

double maxPowDouble(int len) {
    double baseD = 1;
    
    for ( int i = 0; i < len; baseD *= 2, i++ );
    return baseD;
}

int distanceNum(int distance) {
    int amountBit = 1;
    
    for (int i = 1; i < distance; i++, amountBit += 1 );
    return amountBit;
}

int convertDistance( int amountBit) {
    int distanceValue = 1;
    
    for ( int i = 1; i < amountBit; i++, distanceValue *= 2 );
    
    return distanceValue + 1;
}

int powerDistance( int amountBit) {
    int power = 1;
    
    for ( int i = 1; i < amountBit; i++, power *= 2 );
    
    return power;
}
unsigned int bitSequences(int maxValue, int len, int count, int distance) {
    int flag = 1;
    unsigned int maxPower = maxPow(len);
    int arr[len];
    int base = 2;
    int num = maxValue;
    int arrBit[amountBit];
    
    if ( maxValue < 0 ) {
        return count;
    }
    
    for ( int i = 0; maxPower > 0; maxPower /= base, i++ ) {
        int result = num / maxPower;
        
        if ( result != 0 ) {
            num %= maxPower;
        }
        arr[i] = result;
    }
    for (int k = 1 ; k < distance; k++ ) {
        int amountBit = distanceNum(k);
        int distanceValue = convertDistance(amountBit);
        
        for ( int i = len - 1; i >= 0; ) {
            int powerDist = 1;
            int summ = 0;
            int j = i;
        
            for ( ; j > i - amountBit; j--, powerDist *= base ) {
                int temp, buffer;
                
                if ( j < 0 ) {
                    temp = 0;
                } else {
                    temp = arr[j];
                }
            
                buffer = temp * powerDist;
                summ += buffer;
            
            }
        
            i -= amountBit;
            if ( arr[i] == 1 && arr[i+1] == 1 ) {
                flag = 0;
            }
        
            if ( summ == distanceValue ) {
                flag = 0;
                distanceValue = convertDistance(amountBit+1);
                maxPow = 
                for ( ; ; )
            }
            
            if ( flag == 1 && i == 0 ) {
            count += 1;
            }
        }
    }
    
    
    return bitSequences(maxValue-1, len, count, distance);
}

int main() {
    int len, distance;
    int count = 0;
    int maxValue;
    double minDistance;
    
    scanf("%d %d", &len, &distance);
    
    if ( distance == 1 ) {
        minDistance = maxPowDouble(len);
        
        printf("%.0f\n", minDistance);
    } else {
        maxValue = maxPow(len) * 2 - 1;
        
        printf("%d\n", bitSequences(maxValue, len, count, distance));
    }
    
    return 0;
}
