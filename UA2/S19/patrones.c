//patrones.c - dibujo de elementos anidados

#include <stdio.h>

int main (void){
    int filas, i, j;

    //digita cantidad de filas 
    printf("Cantidad de filas: ");
    scanf("%d", &filas);

    //1 Patron * / ciclo interno(i) controla el numero fila
    for (i = 1; i <= filas; i++) {
        for (j = 1; j <= i; j++) {// Ciclo interno (j) imprime asteriscos como el número de la fila actual
        printf("*");
    }
    // Salto de línea al terminar de imprimir los asteriscos de la fila
        printf("\n");
    }

    //Reutilizo codigo e ingreso los otros datos
    //2 Patron 1,12,123,1234 / ciclo externo(i) controla el numero fila
    for (i = 1; i <= filas; i++) {
        for (j = 1; j <= i; j++) {// Ciclo interno (j) imprime los números desde 1 hasta el valor de la fila actual (i)
        printf("%d", j);
    }
    // Salto de línea al terminar de imprimir los numeros de la fila
        printf("\n");
    }
    
    return 0;
}