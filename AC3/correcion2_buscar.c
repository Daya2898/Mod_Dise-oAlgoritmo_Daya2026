#include <stdio.h>
#include <string.h>
#define N 4
int buscar(const char nombres[][15], int n, const char buscado[])
{
    int i;
    // ERROR: en la linea for esta (i = 0; i <= n; i++)
    // POR QUE: siendo este el operador (<=) hace que como ciclo intente leer posición + haya límite del arreglo proboca desbordamiento
    // CORRECCION: Se uso menor (< n).
    for (i = 0; i < n; i++)
        // ERROR: En if (nombres[i] == buscado)
        // POR QUE:En el programa del operador == no sirve para comparar(arreglos de caracteres).
        // CORRECCION: coloque strcmp para comparar ambas cadenas para que salga correctamente.
        if (strcmp(nombres[i], buscado) == 0)
            return i;
    return -1;
}
int main(void)
{
    char nombres[N][15] = {"Arroz", "Frijoles", "Cafe", "Azucar"};
    double precios[N] = {1200, 1500, 3200, 900};
    char buscado[15];
    int pos;
    printf("Producto: ");
    scanf("%14s", buscado);
    pos = buscar(nombres, N, buscado);
    if (pos == -1)
        printf("No existe");

else
    printf("%s cuesta %.2f", nombres[pos], precios[pos]);
return 0;
}