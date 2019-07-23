// В файле task.in задана последовательность символов.
// Вывести в task.out количество вхождений латинских букв, которые встречаются в последовательности.
// Большие буквы считать как маленькие.

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int size = 26;
    int target[size];
    char symbol;
    
    for ( int i = 0; i < size; i++ ) {
        target[i] = 0;
    }
    for ( ; fscanf(in, "%c", &symbol) == 1; ) {
        int count;
        
        if ( symbol >= 'a' && symbol <= 'z' ) {
            count = symbol - 97;
            target[count] += 1;
        }
        if ( symbol >= 'A' && symbol <= 'Z' ) {
            count = symbol - 65;
            target[count] += 1;
        }
    }
    fclose(in);
    for ( int i = 0; i < size; i++ ) {
        if ( target[i] > 0 ) {
            char result = i + 97;
            
            fprintf(out, "%c %d\n",result, target[i]);
        }
    }
    fclose(out);
    
    return 0;
}
