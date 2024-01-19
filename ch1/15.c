#include <stdio.h>

float fahrToCelsius(float fahr) { return (5.0 / 9.0) * (fahr - 32.0); }

/* print Fahrenheit-Celsius table
for fahr = 0, 20, ..., 300; floating-point version */
int main() {
    float fahr, celsius;
    int lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    printf("Fahrenheit-Celsius table\n");
    /* lower limit of temperature table */
    /* upper limit */
    /* step size */
    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fahrToCelsius(fahr));
        fahr = fahr + step;
    }
}
