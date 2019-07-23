#include <stdio.h>

typedef enum {
    MONDAY = 1,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
} Day;

int main() {
    printf("%d\n", MONDAY);
    printf("%d\n", TUESDAY);
    printf("%d\n", WEDNESDAY);
    
    return 0;
}