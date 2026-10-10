// pago.c - se calcula el pago semala de una persona colaboradora

#include <stdio.h>

#define BONO 5000.0

int main(void){
    double horas, pagoHora,  salario ;
    
    //ENTRADA
    printf("Horas trabajadas en la semana:");
    scanf("%lf", &horas);
    printf("Pago por hora:");
    scanf("%lf", &pagoHora);

    //PROCESO
    salario = horas * pagoHora + BONO;

    //Salida impresa
    printf("---------------------------------------------\n");
    printf("%-18s %10.2f\n", "Horas:", horas);
    printf("%-18s %10.2f\n", "Pago por hora:", pagoHora);
    printf("%-18s %10.2f\n", "Bono:", BONO);
    printf("%-18s %10.2f\n", "Pago semanal:", salario);
    printf("---------------------------------------------");

    return 0; 
}
