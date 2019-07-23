// Условие задачи
// Числа шифруются по определенному алгоритму с двумя секретными числовыми ключами – A и B.
// Число умножается на значение ключа A, затем к результату прибавляется значение ключа B.
// Шифруемые числа и значения ключей не превышают по модулю 30000.
// В ходе разведывательной операции стали известны зашифрованные эквиваленты двух чисел.
// Необходимо найти подходящие ключи и расшифровать зашифрованную последовательность чисел.

// Входные данные:
// plain1 encrypted1
// plain2 encrypted2
// length
// <последовательность length зашифрованных чисел>

#include <stdio.h>

int main() {
    int plain1, plain2, encrypted1, encrypted2, length, number, plain;
    int keyA, keyB;
    
    scanf("%d %d", &plain1, &encrypted1);
    scanf("%d %d", &plain2, &encrypted2);
    scanf("%d", &length);
    
    if ( plain1 != 0 && plain2 != 0 ) {
        keyA = (encrypted2 - encrypted1) / (plain2 - plain1);
        keyB = encrypted1 - plain1 * keyA;
        
        for ( int i = 1; i < length; i++ ) {
            scanf("%d ", &number);
            
            plain = (number - keyB) / keyA;
            
            printf("%d ", plain);
        }
        scanf("%d", &number);
        plain = (number - keyB) / keyA;
        printf("%d\n", plain);
    }
    return 0;
}
