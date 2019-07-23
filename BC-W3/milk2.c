// 1. объявляю farmerQuantity, amountNeeded, minPrise=0, и масив размером 1001
// 2. сканю farmerQuantity и amountNeeded
// 3. если farmerQuantity или amountNeeded равны нулю, то печатаю 0 и обрываю програму
// 4. цикл запоняет нулями масив
// 5. считываем количество молока и цену столько раз, сколько у нас фермеров. 
// если кол-во больше допустимого предеа, то делаем его равным пределу. Записываем в ячейку масива под номером равным цене, считаное количество.
// 6. идем по масиву и дописываем в минПрайс произведение цены на количество, одновременно отнимая от amountNeeded количество купленого.
// Если amountNeeded стало равно 0, то печаем в task.out minPrice и обрываем программу.
// Если купили больше, чем надо, то попровляем minPrice и печаем его в файл и обрываем программу.
// 7. если за все это время не скупили нужное кол-во молока, то печатаем 0 и все, прога закончилась.

#include <stdio.h>

int main() {
    FILE *in = fopen("task.in", "r");
    FILE *out = fopen("task.out", "w");
    unsigned long long farmerQuantity;
    long long amountNeeded;
    int size = 1001;
    int array[size];
    unsigned long long amount;
    unsigned long long price;
    unsigned long long minPrice = 0;
    
    fscanf(in, "%lld %lld", &farmerQuantity, &amountNeeded);
    
    if ( amountNeeded == 0 || farmerQuantity == 0 ) {
        fprintf(out, "%lld\n", minPrice);
        fclose(out);
        
        return 0;
    }
    for ( int i = 0; i < size; i++ ) {
        array[i] = 0;
    }
    
    for ( int i = 0; i < farmerQuantity; i++ ) {
        fscanf(in, "%lld %lld", &amount, &price);
        
        if ( amount > 300000000 ) {
            amount = 300000000;
        }
        array[price] = amount;
    }
    
    fclose(in);
    
    for ( int i = 1; i < size; i++ ) {
        minPrice += array[i] * i;
        amountNeeded -= array[i];
        
        if ( amountNeeded == 0 ) {
            fprintf(out, "%lld\n", minPrice);
            fclose(out);
            
            return 0;
        }
        if ( amountNeeded < 0 ) {
            amountNeeded *= -1;
            minPrice -= amountNeeded * i;
            
            fprintf(out, "%lld\n", minPrice);
            fclose(out);
            
            return 0;
        }
    }
    minPrice = 0;
    
    fprintf(out, "%lld\n", minPrice);
    fclose(out);
    
    return 0;
}
