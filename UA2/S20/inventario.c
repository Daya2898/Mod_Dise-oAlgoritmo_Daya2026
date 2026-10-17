//intentario.c - inventario con arreglo paralelos
//consultar productos de una pulperia, conocer el valor total del inventario
//lo esperado 310 -> cafe 1 kg: 12 unidades a 4500.00»; 999 → «Codigo 999 no encontrado»; 0 termina y muestra «Valor del inventario: 217600.00

// inventario.c - inventario con arreglos paralelos
// Consultar productos de una pulpería por código y conocer el valor total del inventario.

#include <stdio.h>

int main(void) {
    // Declaración de arreglos paralelos para los productos
    int codigos[5] = {101, 205, 310, 412, 518}; 
    int existencias[5] = {20, 15, 12, 30, 8};
    float precios[5] = {2400, 1800, 4500, 2100, 3200};
    char descripciones[5][30] = {"Arroz 2 kg", "Frijoles 1 kg", "Cafe 1 kg", "Azucar 2 kg", "Aceite 1 L"};
    
    int codigoBuscado;
    float valorInventario = 0.0; // Acumulador para el valor total del inventario

    // Calculamos el valor total de toda la pulpería recorriendo los arreglos
    for (int i = 0; i < 5; i++) {
        valorInventario += (existencias[i] * precios[i]);
    }

    // centinela (0 para terminar)
    do {
        // Ingreso de código 
        printf("Codigo (0 para terminar): ");
        scanf("%d", &codigoBuscado);

        // Si ingresa 0, finaliza el ciclo
        if (codigoBuscado == 0) {
            break;
        }

        int posicion = -1; // -1 indica inicialmente que el producto no ha sido encontrado

        // Búsqueda lineal: recorre casilla 
        for (int i = 0; i < 5; i++) {
            if (codigos[i] == codigoBuscado) {
                posicion = i; // Guarda la posición  donde se encontró
                break;       // Detiene la búsqueda
            }
        }

        // Si la posición  -1, no se encontró el código
        if (posicion == -1) {
            printf("Codigo %d no encontrado\n", codigoBuscado);
        } else {
            // Si se encontró, muestra la información
            printf("%s: %d unidades a %.2f\n", descripciones[posicion], existencias[posicion], precios[posicion]);
        }

    } while (codigoBuscado != 0);

    // Salida, muestra el valor total acumulado del inventario
    printf("Valor del inventario: %.2f\n", valorInventario);

    return 0;
}


