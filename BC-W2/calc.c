// Считать из task.in строку не более 1000 символов, содержащую неотрицательные целые числа и знаки арифметических операций между ними: + - * /.
// Количество арифметических действий в выражении не превышает 100.
// Вычислить значение выражения и вывести его в task.out в формате %g.

#include <stdio.h>

void sliceShiftLeftD(double array[], int start, int len) {
    for ( int i = start; i < len; i++ ) {
        array[i] = array[i+1];
    }
}

void sliceShiftLeftCh(char array[], int start, int len) {
    for ( int i = start; i < len; i++ ) {
        array[i] = array[i+1];
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int limit = 1000;
    int maxOperations = 100;
    double numbers[limit];
    char operations[maxOperations];
    int len1 = 0;
    int len2 = 0;
    int lenFirst, lenSecond;
    
    for ( int i = 0; fscanf(in, "%lf", &numbers[i]) == 1; i++, len1 += 1, len2 += 1 ) {
        fscanf(in, "%c", &operations[i]);
    }
    len2 -= 1;
    lenFirst = len1;
    lenSecond = len2;
    fclose(in);
    
    for ( int i = 0; i < lenSecond; i++ ) {
        printf("%c\n", operations[i]);
    }
    for ( int i = 0; i < len2; ) {
        if ( operations[i] == '*' || operations[i] == '/' ) {
            if ( operations[i] == '*' ) {
                numbers[i] *= numbers[i+1];
            }
            if ( operations[i] == '/' ) {
                numbers[i] /= numbers[i+1];
            }
            
            sliceShiftLeftD(numbers, i+1, lenFirst);
            sliceShiftLeftCh(operations, i, lenSecond-1);
            
            operations[lenSecond-1] = '\0';
            lenFirst -= 1;
            lenSecond -= 1;
        } else {
            i += 1;
        }
    }
    for ( int i = 0; i < lenFirst; ) {
        if ( operations[i] == '+' || operations[i] == '-' ) {
            if ( operations[i] == '+' ) {
                numbers[i] += numbers[i+1];
            }
            if ( operations[i] == '-' ) {
                numbers[i] -= numbers[i+1];
            }
            
            sliceShiftLeftD(numbers, i+1, lenFirst);
            sliceShiftLeftCh(operations, i, lenSecond-1);
            
            operations[lenSecond-1] = '\0';
            lenFirst -= 1;
            lenSecond -= 1;
        } else {
            i += 1;
        }
    }
    
    fprintf(out, "%g\n", numbers[0]);
    fclose(out);
    
    return 0;
}
