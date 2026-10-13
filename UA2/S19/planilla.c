//planilla.c - calculo de planilla semanal

#include <stdio.h>

//Definicion constantes 
#define CENTINELA  -1
#define LIMITE 48
#define RECARGO 1.5




int main(void){

    int cantidad;
    int i ;
    int conExtra;
    double horas, tarifa, horasExtra, pago, totalPlanilla ;
    int personas;

    //Contadores empienzan de 0
    totalPlanilla = 0;
    conExtra = 0;
    personas = 0; 



     // Lectura previa de las horas antes de entrar al ciclo
     printf("Horas de la semana (-1 para terminar): ");
     scanf("%lf", &horas);

    // Ciclo while que se repite mientras no se digite el centinela  que seria (-1)
     while (horas != CENTINELA) {
     printf("Tarifa por hora: ");// Aquí adentro solicitaremos la tarifa y haremos los cálculos y volveremos a leer las horas
     scanf("%lf", &tarifa);

    // Se evalua si las horas superan el límite establecido con (48 horas)
     if (horas > LIMITE){
        
        //Si hay horas extrras , se calcula y aplica recargo
        horasExtra = horas - LIMITE;
        pago = LIMITE * tarifa + horasExtra * tarifa * RECARGO ;

        //Se incrementa en 1 el contador de personas con horas extra
        conExtra = conExtra + 1;
     } else {
        //Si no se supera el limite, su págo es normal = horas x tarifa
        pago = horas * tarifa;
     }

     //Se mostrara el pago individual de la persona utilizamos %.2f para imprimir 2 decimales
     printf("Pago: %.2f\n", pago);

     //Se acumula el pago de una persona al total de la planilla
     totalPlanilla = totalPlanilla + pago;

     //contador persona procesadas
     personas = personas + 1;

    //Lectura al final del ciclo , indica pedir siguiente valor o el -1 para salir
     printf("Horas de la semana (-1 para terminar): ");
     scanf("%lf", &horas);


    }
    

     //cuando se ingresa -1 muestra resultado final
     printf ("\n--- Resumen Final ---\n");
     printf("Personas: %d\n", personas);
     printf("Con horas extra: %d\n", conExtra);
     printf("Total de la planilla: %.2f\n", totalPlanilla);

     return 0; 

}





