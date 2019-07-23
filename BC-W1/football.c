// Считать с клавиатуры 2 целых положительных числа, количество забитых голов хозяевами и гостями на футбольном матче.
// Вывести на экран результат матча «Home team wins», «Away team wins», «Draw».

#include <stdio.h>

int main() {
    int homeGoals, awayGoals;
    
    scanf("%d %d", &homeGoals, &awayGoals);
    
    if ( homeGoals > awayGoals ) {
        printf("Home team wins\n");
    } else if ( awayGoals > homeGoals ) {
        printf("Away team wins\n");
    } else {
        printf("Draw\n");
    }
    
    return 0;
}
