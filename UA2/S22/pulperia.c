/*pulperia.c
Enunciado: Sistema de inventario para una pulpería con menú y funciones.
Qué se logra: Gestionar productos, ventas, reposiciones y calcular el valor total. Cómo se logra: Usando arreglos paralelos, punteros para modificar datos y validaciones.
*/

#include <stdio.h>

#define MAX 4 // Total de productos que hay pulpería

// Prototipos de las funciones 
int leerEntero(const char mensaje[], int minimo, int maximo);
void listar(const char *productos[], const double precios[], const int existencias[], int n);
int vender(int *existencia, int cantidad);
void reponer(int *existencia, int cantidad);
double valorInventario(const double precios[], const int existencias[], int n);

int main(void) {
    //Arreglos paralelos 
    const char *productos[MAX] = {"Arroz 2 kg", "Frijoles 1 kg", "Cafe 1 kg", "Aceite 1 L"};
    double precios[MAX] = {2400.0, 1800.0, 4500.0, 3200.0};
    int existencias[MAX] = {20, 15, 12, 8};

    int opcion;
    int prod;
    int cant;

    //Ciclo principal del menú
    do {
        printf("\n1. Listar 2. Vender 3. Reponer 4. Valor 0. Salir\n");
        opcion = leerEntero("Opcion (0 a 4): ", 0, 4);

        switch (opcion) {
            case 1:
                //Muestra la lista de productos
                listar(productos, precios, existencias, MAX);
                break;

            case 2:
                //Vender un producto validando existencias
                listar(productos, precios, existencias, MAX);
                prod = leerEntero("Producto (1 a 4): ", 1, MAX);
                cant = leerEntero("Cantidad (1 a 50): ", 1, 50);

                // Se pasa la dirección de la existencia del producto seleccionado usando &
                if (vender(&existencias[prod - 1], cant)) {
                    printf("Vendido: %d x %s = %.2f\n", cant, productos[prod - 1], cant * precios[prod - 1]);
                } else {
                    printf("Solo hay %d unidades\n", existencias[prod - 1]);
                }
                break;

            