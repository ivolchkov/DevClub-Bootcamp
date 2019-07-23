// Молочная компания каждый день покупает молоко у фермеров. У каждого из <farmerQuantity> фермеров есть <amount> литров молока по цене <price>. Найти минимальную стоимость <minPrice>, за которую возможно приобрести <amountNeeded> литров молока. В случае, если у фермеров недостаточно молока, вывести в качестве <minPrice> значение 0.

// В файле task.in заданы целые числа:
// <farmerQuantity> <amountNeeded>
// <amount1> <price1>
// <amount2> <price2>
// .....
// <amountN> <priceN>

// Вывести minPrice в task.out.

// Ограничения:
// 0 <= farmerQuantity <= 100 000 000
// 0 <= amountNeeded <= 300 000 000
// 0 <= amount <= 300 000 000
// 1 <= price <= 1 000

#include <stdio.h>

unsigned long long quantity(FILE *in) {
    unsigned long long quant;
    
    fscanf(in, "%lld", &quant);
    
    return quant;
}

unsigned long long amountNeed(FILE *in) {
    unsigned long long amount;
    
    fscanf(in, "%lld", &amount);
    
    return amount;
}

void selectSort(unsigned long long amount[], unsigned long long price[], unsigned long long size) {
    for ( int i = 0; i < size; i++ ) {
        unsigned long long tempPrice = price[i];
        unsigned long long tempAmount = amount[i];
        int min = i;
        
        for ( int j = i + 1; j < size; j++ ) {
            if ( price[j] < price[min] ) {
                min = j;
            }
        }
        if ( min != i ) {
            price[i] = price[min];
            price[min] = tempPrice;
            
            amount[i] = amount[min];
            amount[min] = tempAmount;
        }
    }
}

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    unsigned long long farmerQuantity = quantity(in);
    unsigned long long amountNeeded = amountNeed(in);
    unsigned long long amount[farmerQuantity];
    unsigned long long price[farmerQuantity];
    unsigned long long minPrice = 0;
    unsigned long long buffer = 0;
    
    if ( amountNeeded == 0 || farmerQuantity == 0 ) {
        fprintf(out, "%lld\n", minPrice);
        fclose(in);
        fclose(out);
        
        return 0;
    }
    for ( int i = 0; i < farmerQuantity; i++ ) {
        fscanf(in, "%lld %lld", &amount[i], &price[i]);
    }
    
    fclose(in);
    selectSort(amount, price, farmerQuantity);
    
    for ( int i = 0; i < farmerQuantity && buffer < amountNeeded; i++ ) {
        buffer += amount[i];
        if ( buffer > amountNeeded ) {
            unsigned long long diff = buffer - amountNeeded;
            
            amount[i] -= diff;
            buffer -= diff;
        }
        minPrice += amount[i] * price[i];
    }
    
    if ( buffer < amountNeeded ) {
        minPrice = 0;
    }
    
    fprintf(out, "%lld\n", minPrice);
    fclose(out);
    
    return 0;
}



