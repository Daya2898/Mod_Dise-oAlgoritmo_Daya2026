//bisiesto.c - Algoritmo del AñobISIESTO 

#include<stdio.h>
int main(void){
    int anio;
    
    //variable para logico
    int esBisiesto;

    printf("Año:");
    scanf("%d", &anio);

    // Usamos '==' para comparar y agrupamos lógicamente
    esBisiesto = (anio  % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
    
    //impresion final
    printf("%d %s\n", anio, esBisiesto ? "es Bisiesto" : "no es Bisiesto");

    return 0;
}