//C2_P3_Compras.c - Gestión de compras en una tienda
/*Sistema de gestión de compras para una tienda de electrónica.
Enunciado: Sistema de gestión de compras y factura detallada.
Qué se logra: Registrar productos, calcular subtotales, descuentos y el total a pagar.
Cómo se logra: Usando arreglos paralelos, validaciones do-while y formato de factura.
Resultado esperado: Factura alineada con productos, subtotales, descuento, impuesto y total final.*/

#include <stdio.h>
#include <string.h>

// CONSTANTES LIMITES Y TASAS
#define MAX_PRODUCTOS 10
#define TASA_IMPUESTO 0.13

// Rangos, porcentajes de descuento
#define LIMITE_DESC_1 100.0
#define LIMITE_DESC_2 500.0
#define LIMITE_DESC_3 1000.0
#define TASA_DESC_1 0.05       // 5% de desc
#define TASA_DESC_2 0.10       // 10% de desc
#define TASA_DESC_3 0.15       // 15% de desc

int main(void) {

    // DEFINICION VARIABLE , ARREGLO PARALELO 
    char nombreCliente[60];                     
    char nombresProd[MAX_PRODUCTOS][30];      
    double precios[MAX_PRODUCTOS];           
    int cantidades[MAX_PRODUCTOS];           
    double subtotales[MAX_PRODUCTOS];         
    
    int numProductos = 0;                     
    char continuar;                          
    double subtotalGeneral = 0.0;             
    double porcentajeDescuentoAplicado = 0.0; 
    double montoDescuento = 0.0;              
    double totalConDescuento = 0.0;           
    double montoImpuesto = 0.0;               
    double totalAPagar = 0.0;                 
    int i;                                    

    printf("=== Compra en la tienda ===\n");

    // RECEPCION NOMBRE CLIENTE 
    printf("Nombre del cliente: ");
    fgets(nombreCliente, sizeof(nombreCliente), stdin);
    nombreCliente[strcspn(nombreCliente, "\n")] = '\0'; // LIMPIA SALTO LINEA

    // REGISTRO PRODUCTOS BUCLE MAX 10
    do {
        printf("Producto %d\n", numProductos + 1);

        // CADENA SI VIENE CON SCANF PREVIO A PARTIR DEL SEGUNDO PRODUC.
        if (numProductos > 0) {
            getchar(); // LIMPIA EL BUFER CONSUMIENDO SALTO LINEA
        }

        // LECTURA PRODUCTO CON ESPACIOS PERMITIDO 
        printf(" Nombre: ");
        fgets(nombresProd[numProductos], sizeof(nombresProd[numProductos]), stdin);
        nombresProd[numProductos][strcspn(nombresProd[numProductos], "\n")] = '\0';

        // VALIDACION PRECION POR PRECIO UNITARIO = POSITIVO
        do {
            printf(" Precio unitario: ");
            scanf("%lf", &precios[numProductos]);

            if (precios[numProductos] <= 0) {
                printf("Error: El precio debe ser mayor que cero.\n");
            }
        } while (precios[numProductos] <= 0);

        // VALIDACION DE CANTIDAD = POSITIVO
        do {
            printf(" Cantidad: ");
            scanf("%d", &cantidades[numProductos]);

            if (cantidades[numProductos] <= 0) {
                printf("Error: La cantidad debe ser mayor que cero.\n");
            }
        } while (cantidades[numProductos] <= 0);

        // CALCULO SUBTOTAL (PRODUCTO Y ACUMULACION)
        subtotales[numProductos] = precios[numProductos] * cantidades[numProductos];
        printf(" Subtotal: %.2f\n", subtotales[numProductos]);
        subtotalGeneral += subtotales[numProductos];

        numProductos++;

        // PREGUNTA SI AGREGA OTRO PRODUCTO (VALIDACION S-N MAYUSCULA-MINUSCULA
        if (numProductos < MAX_PRODUCTOS) {
            do {
                printf("Desea agregar otro producto? (S/N): ");
                scanf(" %c", &continuar); // ESPACIO PARA DESCARTAR ESPACIOS PREVIOS

                if (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n') {
                    printf("Error: Ingrese un valor valido (S o N).\n");
                }
            } while (continuar != 'S' && continuar != 's' && continuar != 'N' && continuar != 'n');
        } else {
            printf("Se ha alcanzado el límite máximo de 10 productos.\n");
            continuar = 'N'; // FUERZA SALIDA SI LLEGA AL MAX
        }

    } while ((continuar == 'S' || continuar == 's') && numProductos < MAX_PRODUCTOS);

    // APLICA DESCUENTO SEGUN TOTAL ACUMULADO 
        if (subtotalGeneral > LIMITE_DESC_3) {
            porcentajeDescuentoAplicado = TASA_DESC_3;
        } else if (subtotalGeneral >= LIMITE_DESC_2) {
            porcentajeDescuentoAplicado = TASA_DESC_2;
        } else if (subtotalGeneral >= LIMITE_DESC_1) {
            porcentajeDescuentoAplicado = TASA_DESC_1;
        } else {
            porcentajeDescuentoAplicado = 0.0;
        }

    montoDescuento = subtotalGeneral * porcentajeDescuentoAplicado;
    totalConDescuento = subtotalGeneral - montoDescuento;

    // CALCULO IMPUESTO CON 13% EN TOTAL CON DESCUENTO Y TOTAL A PAGAR
    montoImpuesto = totalConDescuento * TASA_IMPUESTO;
    totalAPagar = totalConDescuento + montoImpuesto;

    // RESULTADO FINAL FACTURA DETALLADA 
    printf("\n<=================> FACTURA <=================>\n");
    printf("Cliente: %s\n", nombreCliente);
    printf("%-15s %-10s %-8s %-10s\n", "Producto", "Precio", "Cant", "Subtotal");
    
    for (i = 0; i < numProductos; i++) {
        printf("%-15s %10.2f %8d %10.2f\n", nombresProd[i], precios[i], cantidades[i], subtotales[i]);
    }
    
    printf("<===============================================>\n");
    printf("Productos registrados: %d\n", numProductos);
    printf("Subtotal: %.2f\n", subtotalGeneral);
    printf("Descuento: %.2f (%.0f%%)\n", montoDescuento, porcentajeDescuentoAplicado * 100);
    printf("Total con descuento: %.2f\n", totalConDescuento);
    printf("Impuesto (13%%): %.2f\n", montoImpuesto);
    printf("TOTAL A PAGAR: %.2f\n", totalAPagar);
    printf("<================================================>\n");

    return 0;
}