// Написать функцию
// void arrayMerge(int target[], int src1[], int len1, int src2[], int len2)

// Массивы src1[] и src2[] (длиной len1 и len2 соответственно) отсортированы по неубыванию.
// Произвести слияние этих массивов в массив target[], также отсортированный по неубыванию.
// В случае равенства предпочтение отдаётся элементам из первого массива.
// Требуемая сложность: O(N)
#include <stdio.h>

void arrPrint(int array[], int size) {
    for ( int i = 0; i < size; i++ ) {
           printf("%d ", array[i]);
        }
        printf("\n");
}


void arrayMerge(int target[], int src1[], int len1, int src2[], int len2) {
    int i, j, k;
    
    for ( i = 0, j = 0, k = 0; i < len1 && j < len2; k++ ) {
        if ( src1[i] <= src2[j] ) {
            target[k] = src1[i];
            i += 1;
        } else {
            target[k] = src2[j];
            j += 1;
        }
    }
    
    for ( ; i < len1; i++, k++ ) {
        target[k] = src1[i];
    }
    
    for ( ; j < len2; j++, k++ ) {
        target[k] = src2[j];
    }
}

int main() {
    int len1 = 7;
    int len2 = 6;
    int src1[7] = {1,3,5,7,9,12,13};
    int src2[6] = {1,2,6,8,9,10};
    int target[13];
    
    arrayMerge(target,src1,len1,src2,len2);
    arrPrint(target,13);
    return 0;
    
}
