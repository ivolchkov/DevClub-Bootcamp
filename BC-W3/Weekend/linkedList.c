#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int quantity;
    int current;
    float multiplier;
}List;


/*
typedef enum {
    INCREASE,
    REDUCE,
}Action;
*/
void initList(List* list) {
    list->quantity = 100;
    list->current = 0;
    list->multiplier = 1.05;
    
    int* temp = (int*)malloc(sizeof(int) * list->quantity);
    
    if ( temp == NULL ) {
        printf("Unsufficient memory\n");
        return;
    }
    
    list->array = temp;
}

void listPrint(List* list) {
    int limit = list->current - 1;
    printf("[");
    
    for ( int i = 0; i < limit; i++ ) {
        printf("%d, ", list->array[i]);
    }
    
    if ( limit < 0 ) {
        printf("]\n");
    } else {
        printf("%d]\n", list->array[limit]);
    }
}


void resize(List* list, int reduce) {//Action action c enum
    int newQuantity;
    
    if ( reduce ) {  //action == REDUCE c enum
        newQuantity = list->quantity / list->multiplier;
        printf("Reduce size\n");
    } else {  //else if ( action == INCREASE )
        newQuantity = list->quantity * list->multiplier;
        printf("Increase size\n");
    }
    
    int *temp = (int*)realloc(list->array, newQuantity * sizeof(int));
    
    if ( !temp ) {
        printf("Unsufficient memory\n");
        return;
    }
    
    list->array = temp;
    list->quantity = newQuantity;
    printf("Memory reallocated (%d, %d)\n", list->quantity, list->current);
}
void pushBack(List* list, int value) {
    if ( list->current == list->quantity ) {
        resize(list, 0);//resize(list, INCREASE)
    }
    list->array[list->current] = value;
    list->current += 1;
}

void fillList(List* list, int elems) {
    for ( int i = 0, counter = 1; i < elems; i++, counter++ ) {
        pushBack(list, counter);
    }
}

int pop(List* list) {
    int result = list->array[list->current - 1];
    list->current -= 1;
    
    float diff = (float)list->quantity / (float)list->current;
    if ( diff > list->multiplier && list->quantity > 100 ) {
        resize(list, 1);//resize REDUCE
    }
    
    return result;
}

int main() {
    List list;
    int temp;
    
    initList(&list);
    // listPrint(&list);
    fillList(&list, 50);
    // listPrint(&list);
    fillList(&list, 50);
    fillList(&list, 10);
    // pushBack(&list, 666);
    listPrint(&list);
    
    for ( int i = 7; i > 0; i-- ) {
        temp = pop(&list);
    }
    
    listPrint(&list);
    // printf("%d\n", list.quantity);
    // printf("%d\n", list.current);
    // printf("%f\n", list.multiplier);
    // printf("%p\n", list.array);
    // printf("%p\n", &list);
    
    return 0;
}