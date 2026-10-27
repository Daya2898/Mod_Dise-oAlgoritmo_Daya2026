/*conversiones.c
 Qué se logra: Crear funciones propias para calcular temperaturas, monedas, años bisiestos y notas.
 Cómo se logra:  Conversion de temperatura/ conversion de monedas-colones a dolar
 */

#include <stdio.h>
#define TIPO_CAMBIO 510.0 //COLONES X DOLAR

//Prototipos funciones 
double celsiusAFahrenheit(double celsius);//devuelve grados f
double colonesADolares(double colones);//devuelve dolares
int esBisiesto(int anio);            //1 o 0
int esNotaValida(double nota);  //1 o 0

int main(void) { //funcion principal
    //1 Celsius a Fahrenheit 25 -> 77.0
    printf("25 C = %.1f F (esperado 77.0)\n", celsiusAFahrenheit(25));

    //2 Colones a Dólares 5100 -> 10.00
    printf("5100 colones = %.2f dolares (esperado 10.00)\n", colonesADolares(5100.0));

    //3 Año Bisiesto 2024 -> 1, 1900 -> 0
    printf("2024 bisiesto: %d (esperado 1)\n", esBisiesto(2024));
    //Prueba anio no bisiesto
    printf("1900 bisiesto: %d (esperado 0)\n", esBisiesto(1900));

    //4 Validación de Nota 105 -> 0, 85 -> 1
    printf("Nota 105 valida: %d (esperado 0)\n", esNotaValida(105));
    printf("Nota 85 valida: %d (esperado 1)\n", esNotaValida(85));

    return 0;
}

//F1 conversion temperatura
double celsiusAFahrenheit(double celsius) {
    return celsius * 9.0 / 5.0 + 32.;
}

// F2 conversion de moneda
double colonesADolares(double colones) {
    return colones / TIPO_CAMBIO;
}

//F3  Anio bisiesto
int esBisiesto(int anio) {
    return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
} 

//F4 Valida si la nota está entre 0 y 100 /devuelve 1 si es verdad o 0 si es falso.
int esNotaValida(double nota) {
    return (nota >= 0 && nota <= 100);
}