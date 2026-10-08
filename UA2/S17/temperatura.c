//temperatura.c conversion  grados Celsius a Fahrenheit

#include <stdio.h>

int main(void){
    double celsius, fahrenheit;

    //ENTRADA
    printf("Temperatura en grados Celsius:");
    scanf("%lf", &celsius);
    

    //Proceso
    fahrenheit = celsius *  9 / 5 + 32;

    //Salida
    printf("°C equivalente a: %.2lf °f", fahrenheit);

    return 0;
}
