// В файле task.in даны два целых положительных числа.
// Записать в файл task.out наименьшее общее кратное этих чисел.

#include <stdio.h>

int gcd(int a, int b) {
    if ( b == 0 ) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    int a, b;
    int lcm;
    
    fscanf(in, "%d %d", &a, &b);
    fclose(in);
    
    lcm = (a / gcd(a, b)) * b;
    
    fprintf(out, "%d\n", lcm);
    fclose(out);
    return 0;
}
