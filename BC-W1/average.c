// unsigned int average(unsigned int a, unsigned int b)
// Вернуть среднее арифметическое двух положительных целых чисел. Использовать только тип unsigned int.
// Если среднее значение не является целым, то округлить его к ближайшему целому в меньшую сторону.

unsigned int average(unsigned int a, unsigned int b) { 
    return a / 2 + b / 2 + ( a % 2 + b % 2) / 2;
}