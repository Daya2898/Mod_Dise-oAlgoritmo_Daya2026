//salario.c - Salario-Neto
#include <stdio.h>

int main(void){
    const double DEDUCCION = 0.10; //CONSTANTE DE DEDUCCION

    //VARIABLES 
    double horas, tarifaHora, bruto, deduccion, neto;

    //ENTRADA 
    printf("Horas trabajadas: ");
    scanf ("%lf", &horas);

    printf("Pago por hora: ");
    scanf ("%lf", &tarifaHora);

    //PROCESO
    bruto = horas * tarifaHora;
    deduccion = bruto * 0.10;
    neto = bruto - deduccion;

    //SALIDAS
    printf("Salario bruto: %10.2f\n", bruto);
    printf("Deduccion: %10.2f\n", deduccion);
    printf("Salario neto: %10.2f\n", neto);

    return 0;

}