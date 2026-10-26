/*conversiones.c
 Qué se logra: Crear funciones propias para calcular temperaturas, monedas, años bisiestos y notas.
 Cómo se logra: Usando prototipos, parámetros, tipos de retorno (double e int) y return.
 */

#include <stdio.h>

//Prototipos funciones 
double celsiusAFahrenheit(double c);
double colonesADolares(double c);
int esBisiesto(int anio);
int esNotaValida(double nota);

int main(void) {
    //1 Celsius a Fahrenheit 25 -> 77.0
    printf("25 C = %.1f F (esperado 77.0)\n", celsiusAFahrenheit(25.0));

    //2 Colones a Dólares 5100 -> 10.00
    printf("5100 colones = %.2f dolares (esperado 10.00)\n", colonesADolares(5100.0));

    //3 Año Bisiesto 2024 -> 1, 1900 -> 0
    printf("2024 bisiesto: %d (esperado 1)\n", esBisiesto(2024));
    printf("1900 bisiesto: %d (esperado 0)\n", esBisiesto(1900));

    //4 Validación de Nota 105 -> 0, 85 -> 1
    printf("Nota 105 valida: %d (esperado 0)\n", esNotaValida(105.0));
    printf("Nota 85 valida: %d (esperado 1)\n", esNotaValida(85.0));

    return 0;
}

//F1 Recibe grados Celsius y devuelve Fahrenheit
double celsiusAFahrenheit(double c) {
    return c * 9.0 / 5.0 + 32.0;
}

// F2 Recibe colones y los divide entre la tasa de cambio-510.0
double colonesADolares(double c) {
    return c / 510.0;
}

//F3 Devuelve 1 si el año es bisiesto, o 0 si no 
int esBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

//F4 Valida si la nota está entre 0 y 100 /devuelve 1 si es verdad o 0 si es falso.
int esNotaValida(double nota) {
    return nota >= 0.0 && nota <= 100.0;
}