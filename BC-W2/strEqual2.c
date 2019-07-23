// В файле task.in заданы две строки длиной не более 100 символов каждая.
// Если строки равны, вывести в task.out слово "yes" - иначе вывести "no".

#include <stdio.h>

int strEqual(char str1[], char str2[]) {
    for ( int index = 0; str1[index] == str2[index]; index++ ) {
        if ( str1[index] == '\0' ) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = 100;
    char str1[len];
    char str2[len];
    int check;
    
    fscanf(in, "%100s %100s", str1, str2);
    fclose(in);
    check = strEqual(str1, str2);
    if ( check ) {
        fprintf(out, "yes\n");
    } else {
        fprintf(out, "no\n");
    }
    fclose(out);
    
    return 0;
}
