#include <stdio.h>

int main(int argc, char const *argv[])
{
    char a = 'A';
    short b = 5;
    int c = 42;
    long long d = 70;
    
   /* printf("size of (a) char : %lu\n", sizeof(a));
    printf("size of (b) short : %lu\n", sizeof(b));
    printf("size of (c) int : %lu\n", sizeof(c));
    printf("size of (d) long long : %lu\n", sizeof(d));
    
    printf("\nvalue in (a) char : %c\n", a);
    printf("value in (b) short : %d\n", b);
    printf("value in (c) int : %d\n", c);
    printf("value in (d) long long : %lli\n", d);
    
    printf("\npointer of (a) char : %p\n", &a);
    printf("pointer of (b) short : %p\n", &b);
    printf("pointer of (c) int : %p\n", &c);
    printf("pointer of (d) long long : %p\n", &d);  */
    
    
    int m = 0;
    int k = 0;
    
    printf("m && k %d\n", m&&k );
    printf("m || k %d\n", m||k );
    
    return 0;
}