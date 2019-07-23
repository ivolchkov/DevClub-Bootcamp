// В файле task.in дана строка длиной не более 100 символов.
// Прочитать строку в память и произвести ее реверс.
// Результат вывести в task.out.

#include <stdio.h>

int strLen(char str[]) {
    int len = 0;
    
    for ( ; str[len] != '\0'; len++ );
    return len;
}

void arrPrint(FILE *out, char str[], int size) {
    for ( int i = size - 1; i > 0; i-- ) {
        fprintf(out, "%c", str[i]);
    }
    fprintf(out, "%c\n", str[0]);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 100;
    char str[size];
    int arrLen;
    
    fscanf(in, "%100s", str);
    arrLen = strLen(str);
    
    arrPrint(out, str, arrLen);
    
    fclose(in);
    fclose(out);
    
    return 0;
}
