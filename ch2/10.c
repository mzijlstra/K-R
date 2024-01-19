#include <stdio.h>

int lower(int c) { return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c; }

int main() {
    printf("%c\n", lower('A'));
    printf("%c\n", lower('B'));
    printf("%c\n", lower('C'));
    printf("%c\n", lower('D'));
    printf("%c\n", lower('E'));
    printf("%c\n", lower('F'));
    printf("%c\n", lower('G'));
    printf("%c\n", lower('H'));
    printf("%c\n", lower('I'));
    printf("%c\n", lower('J'));
    printf("%c\n", lower('K'));
    printf("%c\n", lower('L'));
    printf("%c\n", lower('M'));
    printf("%c\n", lower('N'));
    printf("%c\n", lower('O'));
    printf("%c\n", lower('P'));
    printf("%c\n", lower('Q'));
    printf("%c\n", lower('R'));
    printf("%c\n", lower('S'));
    printf("%c\n", lower('T'));
    printf("%c\n", lower('U'));
    printf("%c\n", lower('V'));
    printf("%c\n", lower('W'));
    printf("%c\n", lower('X'));
    printf("%c\n", lower('Y'));
    printf("%c\n", lower('Z'));
}
