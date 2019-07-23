#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,b;
    
    printf("Введите а и b: \n");
    
    scanf("%d %d", &a, &b);
    
    printf("%d + %d = %d \n", a, b, a+b );
    printf("%d - %d = %d \n", a, b, a-b );
    printf("%d * %d = %d \n", a, b, a*b );
    printf("%d / %d = %d \n", a, b, a/b );
    printf("%d %% %d = %d \n", a, b, a%b );
    
    if ( a == b )
    {
        printf("a == b\n");
    }else if (a<b){
       printf("a < b\n"); 
    }else{
        printf("a > b\n"); 
    }
    
    
    printf("%d == %d = %d \n", a, b, a==b );
    printf("%d != %d = %d \n", a, b, a!=b );
    
    
    
    
    
    return 0;
}