//promedio.c - promediar las notas sin aceptar imposibles.

#include <stdio.h>

int main (void){

    int cantidad, i;
    double nota, suma, promedio;
    
    suma = 0;// acumulador de suma en 0

    do{  //1:Valida cantidad notas estando entre 1 y 10
        printf("Cuantas notas (1 a 10): ");
        scanf("%d", &cantidad); 
     } while (cantidad < 1 || cantidad >10);

    //Ciclo for para recorrer y solicitar nota segun cantidad
    for ( i = 1; i <= cantidad; i++){
        //2.valida cada nota individual 0 y 100
        do{
        printf("Nota %d (0 a 100): ", i);
        scanf("%lf", &nota);
        } while (nota < 0 || nota >100);

    //sumamos notas que pasaron validacion
    suma = suma + nota;
    }
    
    //Se calcula promedio dividiendo suma total entre cantidad nota valida
    promedio = suma / cantidad;

    //Resultado final usando dos decimales
    printf("Suma: %.2f\n", suma);
    printf("Promedio: %.2f\n", promedio);
    
    return 0;
}