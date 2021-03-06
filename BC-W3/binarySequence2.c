#include <stdio.h>

int main() {
    FILE *in1 = fopen("task.in", "r");
    FILE *in2 = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int len = 0;
    int units = 0;
    char buffer;
    int count = 0;
    
    for ( ; fscanf(in1, "%c", &buffer) == 1; len++ ) {
        if ( buffer == '1' ) {
            units += 1;
        }
    }
    fclose(in1);
    
    for ( int i = 0, limit = len - units; i < len && fscanf(in2, "%c", &buffer) == 1; i++ ) {
        if ( buffer == '0' && i >= limit ) {
            count += 1;
        }
    }
    fclose(in2);
    
    fprintf(out, "%d\n", count);
    fclose(out);
    
    return 0;
}
