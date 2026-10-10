//descuento.c - Descuento por monto
#include <stdio.h>

#define MINIMO 50000.0 

int main(void){
    const double TASA = 0.10; //descuento en compras de 50000 o mas

    //Variables 
    double compra, descuento, total; 

    printf("Monto de la compra:");
    scanf("%lf", &compra);

    // PROCESO
    if (compra >= MINIMO) {
        descuento = compra * 0.10; // codigo si es verdadero
    } else {
        descuento = 0 ; //codigo si es falso
    }
     
    total = compra - descuento;

    //Salida
    printf("Descuento: %.2lf\n", descuento);
    printf("Total a pagar: %.2lf\n", total);
    
    return 0;
}
