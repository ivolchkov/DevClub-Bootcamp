// Нарисовать таблицу Пифагора (умножения) с форматированием и разметкой для заданных диапазонов по горизонтали и вертикали.
// Расстояние от края экрана до чисел в заголовке строк - не менее одного пробела.
// Расстояние от вертикальной черты до чисел - не менее одного пробела.
// Расстояние между числами в таблице - не менее одного пробела.
// Ширина всех колонок должна быть одинаковой.
// В вопросе расставления пробелов руководствуйтесь здравым смыслом и примером.
#include <stdio.h>

int shift(int last_v, int last_h) {
    int multiple;
    int k = 0;
    
    if ( last_v < 0 || last_h < 0 ) {
        k += 1;
    }
    multiple = last_v * last_h;
    if ( multiple < 0 ) {
        for ( int i = multiple; i < 0; i /= 10 ) {
            k += 1;
        }
    } else {
        for ( int i = multiple; i > 0; i /= 10 ) {
            k += 1;
        }
    }
    
    return k;
}

int shiftVer(int last_v, int first_v) {
    int k = 0;
    
    if ( first_v < 0 && last_v > 0 ) {
        k += 1;
    }
    if ( last_v < 0 ) {
        k += 1;
        for ( int i = last_v; i < 0; i /= 10 ) {
            k += 1;
        }
    } else {
        for ( int i = last_v; i > 0; i /= 10 ) {
            k += 1;
        }
    }
    return k;
}

void layout(int first, int last, int shift__hor, int shift_ver) {
    char spac = ' ';
    int result;
    
    printf(" %*c |", shift_ver, spac);
    for ( int i = first; i < last; i++ ) {
        printf(" %*d", shift__hor, i);
    }
    printf(" %*d\n", shift__hor, last);
    
    result = last - (first - 1);
    if ( result < 0 ) {
        result *= -1;
    }
    shift_ver += 2;
    for ( int i = 0; i < shift_ver; i++ ) {
        printf("-");
    }
    printf("+");
    shift__hor += 2;
    for ( int i = 0; i < result; i++ ) {
        for ( int j = 1; j < shift__hor; j++ ) {
            printf("-");
        }
    }
    printf("\n");
}

int main() {
    int first_hor, last_hor, first_ver, last_ver;
    int shift_hor, shift_ver, trueLastHor, trueLastVer;
    int compare;
    
    scanf("%d %d %d %d", &first_hor, &last_hor, &first_ver, &last_ver);
    
    trueLastHor = last_hor;
    trueLastVer = last_ver;
    if ( first_hor < 0 ) {
        compare = -first_hor;
        if ( compare >= last_hor ) {
            trueLastHor = -compare;
        }
    }
    if ( first_ver < 0 ) {
        compare = -first_ver;
        if ( compare >= last_ver ) {
            trueLastVer = -compare;
        }
    }
    shift_hor = shift(trueLastVer, trueLastHor);
    shift_ver = shiftVer(trueLastVer, first_ver);
    layout(first_hor, last_hor, shift_hor, shift_ver);
    
    for ( int i = first_ver; i <= last_ver; i++ ) {
        printf(" %*d |", shift_ver, i);
        for ( int j = first_hor; j < last_hor; j++ ) {
            printf(" %*d", shift_hor, i*j);
        }
        printf(" %*d\n", shift_hor, last_hor*i);
    }
    
    return 0;
}
