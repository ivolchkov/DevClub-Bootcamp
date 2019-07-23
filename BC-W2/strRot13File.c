// Считать из файла task.in в память строку длиной не более 100 символов.
// Зашифровать её по алгоритму ROT13.
// Результат вывести в task.out.

#include <stdio.h>

void strRot13(FILE *out, char str[]) {
    for ( int index = 0, buffer = str[index]; buffer != '\0'; buffer = str[index] ) {
        if ( buffer >= 'A' && buffer <= 'Z' ) {
            if ( buffer >= 'A' && buffer <= 'M' ) {
                buffer += 'n' - 'a';
            } else {
                buffer -= 'n' - 'a';
            }
            str[index] = buffer;
        }
        if ( buffer >= 'a' && buffer <= 'z' ) {
            if ( buffer >= 'a' && buffer <= 'm' ) {
                buffer += 'n' - 'a';
            } else {
                buffer -= 'n' - 'a';
            }
            str[index] = buffer;
        }
        fprintf(out, "%c", buffer);
        index += 1;
    }
    fprintf(out, "\n");
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = 100;
    char str[len];
    
    fscanf(in, "%100s", str);
    fclose(in);
    strRot13(out, str);
    fclose(out);
    
    return 0;
}
