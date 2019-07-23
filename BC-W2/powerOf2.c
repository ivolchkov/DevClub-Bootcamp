// int powerOf2(int exponent)
// Возвести 2 в данную целую неотрицательную степень.
// Воспользоваться побитовыми операциями.

int powerOf2(int exponent) {
    return 1 << exponent;
}

int main(int argc, char const *argv[])
{
    int exp = 3;
    
    powerOf2(exp);
    
    printf("%d\n", powerOf2(exp));
    return 0;
}