//intercambio.c - intercambio antes y despues 
#include<stdio.h>

int main(void){
    //Declaracion
    int a = 5;
    int b = 9;
    int aux;
    
    //Muestra valores antes
    printf("============================\n");
    printf("Antes: a = %d b = %d\n", a, b);

    //PROCESO INTERCAMBIO
    aux = a;
    a   = b;
    b   = aux;

    //Salida intercambio
    printf("Despues: a = %d b = %d\n", a, b);
    printf("============================\n");
    return 0;
}