//PR_P1_PagoVendedor.c
//Distribuidora paga a sus vendedores una comision sobre ventas del mes. se recibe el nombre del vendedor y ventas de cada cada una de las 4 semanas del mes, su comision es de 5% ventas y en bono 50 si la venta del mes superan 2000, y con una retencion de 2% + bono . con pago final  comision + bono - retencion.
//Se Logra que: mostrar ventas de cada semana, mes y detalle de pago del vendedor con sus decimales .
// Se hace como : lee el nombre con fgets
//un for recorriendo 4 semanas, con do-while que repita lectura mientras sea venta negativa
//acumula ventas en una variable acumuladora
//calculo de comision,bono,retencion y pago con constantes
//final: todo con printf y %.2f
//Los resultados son Carlos Vega, 600, 450, 700, 500; en Ventas mes : 2250.00 | Comision: 112.50 | Bono:50.00, Retencion: 3.25 | Pago mes :159.25.

 
#include <stdio.h>
#include <string.h>
 
//Constantes 
#define SEMANAS 4                    //cantidad de semanas del mes 
const double TASA_COMISION  = 0.05;  // 5 % de las ventas del mes 
const double TASA_RETENCION = 0.02;  // 2 % de (comision + bono) 
const double BONO           = 50.0;  // bono fijo si se supera el limite 
const double LIMITE_BONO    = 2000.0; // ventas minimas (exclusivo) para el bono 
 
int main(void){

    char nombre[50];            // nombre del vendedor 
    char etiqueta[20];          // texto "Semana N:" para imprimir 
    double ventas[SEMANAS];     // ventas de cada semana 
    double ventasMes = 0.0;     // acumulador de ventas del mes 
    double comision;            // comision sobre las ventas 
    double bono = 0.0;          // bono (0 si no supera el limite) 
    double retencion;           // retencion sobre comision + bono 
    double pago;                // pago final del mes 
    int i;                      // indice del for 
 
    printf("=== Pago del vendedor ===\n");
 
    //Lectura del nombre 
    printf("Nombre del vendedor: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';   // quita el salto de linea 
 
    // Lectura y validacion de las ventas 
    for (i = 0; i < SEMANAS; i++)
    {
        do
        {
            printf("Ventas de la semana %d: ", i + 1);
            scanf("%lf", &ventas[i]);
            if (ventas[i] < 0)
            {
                printf("Error: la venta no puede ser negativa.\n");
            }
        } while (ventas[i] < 0);
 
        ventasMes += ventas[i];             //acumula 
    }
 
    // Calculos 
    comision = ventasMes * TASA_COMISION;
    if (ventasMes > LIMITE_BONO){
        bono = BONO;
    }
    retencion = (comision + bono) * TASA_RETENCION;
    pago = comision + bono - retencion;
 
    //Resultados (etiqueta a la izquierda, valor a la derecha) 
    printf("\n------- Pago de %s -------\n", nombre);
    for (i = 0; i < SEMANAS; i++){
        sprintf(etiqueta, "Semana %d:", i + 1);
        printf("%-18s%11.2f\n", etiqueta, ventas[i]);
    }
    printf("%-18s%11.2f\n", "Ventas del mes:", ventasMes);
    printf("%-18s%11.2f\n", "Comision (5%):", comision);
    printf("%-18s%11.2f\n", "Bono:", bono);
    printf("%-18s%11.2f\n", "Retencion (2%):", retencion);
    printf("%-18s%11.2f\n", "Pago del mes:", pago);
 
    return 0;
}

