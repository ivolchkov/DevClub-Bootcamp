#include <stdio.h>

typedef int (*function)(int , int);

typedef enum {
    ADD = 1,
    SUB,
    DIV,
    MULT,
    EX,
} Choose;

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

int div(int x, int y) {
    return x / y;
}

int mult(int x, int y) {
    return x * y;
}

int unimplemented(int x, int y) {
    printf("Such actrion is not supported, choose another one.\n");
    return 0;
}

function fabric(int choose) {
    switch(choose) {
        case ADD :
            return add;
        case SUB :
            return sub;
        case DIV :
            return div;
        case MULT :
            return mult;
        default :
            return unimplemented;
    }
}

int main() {
    int x, y;
    int choose;
    
    for ( ;  ;  ) {
        printf("Enter the numbers :\n");
        scanf("%d %d", &x, &y);
        
        printf("\nChoose the action: \n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Divide\n");
        printf("4. Multiple\n");
        printf("5. Exit\n");
        
        scanf("%d", &choose);
        if ( choose == EX ) {
            printf("Thank you for choosing our software. Goodbye\n");
            break;
        }
        printf("\nThe result: %d \n", fabric(choose)(x, y)); //add(x, y)
        printf("\n--------------------------------------------\n");
    }
    
    return 0;
}
