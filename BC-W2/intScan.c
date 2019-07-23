// Считать число из файла и вернуть его.

int intScan(FILE *in) {
    int number;
    
    fscanf(in, "%d", &number);
    return number;
}
