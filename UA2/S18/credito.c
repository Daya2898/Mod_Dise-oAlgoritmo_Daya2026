//credito.c - Aprobacion de credito

#include <stdio.h>

int main(void){
    // Declaración de variables para datos numéricos y de texto
    double salario, cuota;
    int antiguedad;
    char respDeudas, respFiador;
    //Variables enteras (1 = Verdadero, 0 = Falso)
    int capacidadPago, tieneDeudas, tieneFiador, aprobado;

    //Captura de datos financieros del usuario 
    printf("Salario mensual:");
    scanf("%lf", &salario);

    printf("Cuota mensual del crédito:");
    scanf("%lf", &cuota);

    //Lectura respuestas
    printf("¿Tiene deudas atrasadas? (S/N)\n");
    scanf(" %c", &respDeudas); //El espacio antes de %c es importante para limpiar el buffer

    printf("Años de antigüedad laboral:\n");
    scanf("%d", &antiguedad);

    printf("¿Tiene fiador? (S/N)\n");
    scanf(" %c", &respFiador);

    //Captura de datos financieros del usuario
    capacidadPago = salario >= cuota *3;
    tieneDeudas = (respDeudas == 'S' || respDeudas == 's');
    tieneFiador = (respFiador == 'S' || respFiador == 's');

    //Condición final
    aprobado = capacidadPago && ! tieneDeudas && (antiguedad >= 1 || tieneFiador);

    //Fue aprodado o no impresion 
    if (aprobado) {
        printf("Credito aprobado.\n");
    } else {
        printf("Credito rechazado\n");
    }

    return 0;
}