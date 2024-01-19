#include <stdio.h>

int main() {
    unsigned char a = 255;
    printf("unsigned char: %d\n", a);
    a++;
    printf("unsigned char: %d\n", a);

    char a2 = 127;
    printf("char: %d\n", a2);
    a2++;
    printf("char: %d\n", a2);

    unsigned short b = 65535;
    printf("unsigned short: %d\n", b);
    b++;
    printf("unsigned short: %d\n", b);

    short b2 = 32767;
    printf("short: %d\n", b2);
    b2++;
    printf("short: %d\n", b2);

    unsigned int c = 4294967295;
    printf("unsigned int: %u\n", c);
    c++;
    printf("unsigned int: %u\n", c);

    int c2 = 2147483647;
    printf("int: %d\n", c2);
    c2++;
    printf("int: %d\n", c2);

    unsigned long d = 0xffffffffffffffff;
    printf("unsigned long: %lu\n", d);
    d++;
    printf("unsigned long: %lu\n", d);

    long d2 = 0x7fffffffffffffff;
    printf("long: %ld\n", d2);
    d2++;
    printf("long: %ld\n", d2);

    unsigned long long e = 18446744073709551615;
    printf("unsigned long long: %llu\n", e);
    e++;
    printf("unsigned long long: %llu\n", e);

    long long e2 = 9223372036854775807;
    printf("long long: %lld\n", e2);
    e2++;
    printf("long long: %lld\n", e2);

    float f = 3.402823e+38;
    printf("float: %f\n", f);
    f *= 10;
    printf("float: %f\n", f);

    double g = 1.797693e+308;
    printf("double: %f\n", g);
    g *= 10;
    printf("double: %f\n", g);

    long double h = 1.797693e+308;
    printf("long double: %Lf\n", h);
    h *= 10;
    printf("long double: %Lf\n", h);

    return 0;
}
