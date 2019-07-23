#include <stdio.h>

int main(int argc, char const *argv[])
{
    int size;
    int counter = 0;
    
    scanf("%d", &size);
    
    // while (counter <= size ) {
    //     printf("%d\n", counter);
    //     counter += 1;
    // }
    
    do {
         printf("%d\n", counter);
         counter += 1;
    } while (counter <= size );
    
    
    
    // for (int i = 0, last = size - 1; i < size; i++)
    // {
    //     for (int j = 0; j < last; j++)
    //     {
    //         printf("1 ");
    //     }
    //     printf("1\n");
    // }
    return 0;
}
