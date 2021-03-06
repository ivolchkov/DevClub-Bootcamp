// В файле task.in дана последовательность символов.
// Перевести все буквы в верхний регистр и вывести результирующую последовательность в файл task.out

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    char a;
    
    for ( ; fscanf(in, "%c", &a) != -1; ) {
        if ( a > 96 && a < 123 ) {
            fprintf(out, "%c", a-32);
        } else {
            fprintf(out, "%c", a);
        }
    }
    fprintf(out, "\n");
    fclose(in);
    fclose(out);
    return 0;
}
