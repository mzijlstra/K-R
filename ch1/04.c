#include <stdio.h>

/* print Celsius-Fahrenheit table
for fahr = 0, 20, ..., 300; floating-point version */
int main() {
    float fahr, celsius;
    int lower, upper, step;
    lower = -30;
    upper = 100;
    step = 10;
    printf("Celsius-Farenheit table\n");
    /* lower limit of temperature table */
    /* upper limit */
    /* step size */
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
