//billetes. c - 
#include <stdio.h>

int main(void){
    //definicion de variables 
    int monto, resto, cantidad;

    //ENTRADAS LEE MONTO = 47500
    printf("Monto a desglosar:");
    scanf("%d, &monto");

    //PROCESOS : division entera 47500 / 2000 -> cantidad =2
    cantidad = resto / 20000;

    //% MODEL ES EL RESIDUO: 475000 % 20000 -> RESTO = 7500
    resto = resto % 20000;

    //MUESTRE -> BILLETES DE 2000: 2
    printf("Billetes de 0000: %d\n", cantidad);

    cantidad = resto / 10000; //seria 75000 / 5000 -> cantidad = 0
    //forma compacta de resto = resto % 10000 -> resto = 7500
    resto %= 10000; 
    printf("Billetes de 10000: %d\n", cantidad); // -> 0

    cantidad = resto / 5000; //seria 75000 / 5000 -> cantidad = 1
    resto %= 10000; 
    printf("Billetes de 5000: %d\n", cantidad); // -> -1

    cantidad = resto / 2000; //seria 2500 / 2000 -> cantidad = 1
    resto %= 2000; 
    printf("Billetes de 2000: %d\n", cantidad); // -> 1

    cantidad = resto / 1000; //seria 500 / 1000 -> cantidad = 0
    resto %= 1000; 
    printf("Billetes de 1000: %d\n", cantidad); // -> 0

    //Lo que queda se entrega en monedas -> en monedas 500
    printf("En monedas : %d\n", resto);

    return 0;
}