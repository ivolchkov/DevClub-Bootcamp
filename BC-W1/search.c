#include <stdio.h>

int arraySearch(FILE *in, int size, int needle) {
    int array[size];
    
    for ( int loaded = 0; loaded < size && fscanf(in, "%d", &array[loaded]) == 1; loaded++ ) {
        if ( needle == array[loaded] ) {
            return loaded;
        }
    }
    return -1;
}

int main() {
    int needle;
    int size = 100;
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    
    fscanf(in, "%d", &needle);
    fprintf(out, "%d\n", arraySearch(in, size, needle));
    
    fclose(in);
    fclose(out);
    
    return 0;
}