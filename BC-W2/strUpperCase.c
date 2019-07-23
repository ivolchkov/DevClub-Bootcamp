void strUpperCase(char str[]) {
    for ( int index = 0, buffer = str[index]; buffer != '\0'; buffer = str[index] ) {
        if ( buffer >= 'a' && buffer <= 'z' ) {
            buffer -= 'a' - 'A';
            str[index] = buffer;
        }
        index += 1;
    }
}
