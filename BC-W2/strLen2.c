// В файле task.in дана строка длиной не более 100 символов и не содержащая whitespace-символов (пробелов и прочего).
// Прочитать строку в память и подсчитать ее длину.
// Результат вывести в task.out.

#include <stdio.h>

int strLen(char str[], int size) {
    int len = 0;
    
    for ( ; str[len] != '\0'; len += 1 );
    return len;
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = 100;
    char str[len];
    
    fscanf(in, "%100s", str);
    fclose(in);
    
    fprintf(out, "%d\n", strLen(str, len));
    fclose(out);
    
    return 0;
}
