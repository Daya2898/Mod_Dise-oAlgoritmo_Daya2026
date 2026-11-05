#include <stdio.h>
// ERROR: void en sumarPuntos tiene un (int puntos, int compra) { puntos = puntos + compra / 1000; }
// POR QUE: recibe por valor y no modifica la variable del main, entonces el total siempre queda en 0
// CORRECCION: colocar puntero (int puntos) para actualizar su valor en memoria y de 17 en puntos acumulados.
void sumarPuntos(int *puntos, int compra)
{
    *puntos = *puntos + compra / 1000;
}
int main(void)
{
    int puntos = 0, compra, i;
    for (i = 1; i <= 3; i++)
    {
        printf("Compra %d: ", i);
        // ERROR: En scanf estaba ("%d", compra);.
        // POR QUE: faltaba  el operador de direccion & que se necesita para poder almacenar el valor leido en la variable compra si no da eror.
        // CORRECCION:Se agrego el ampersand antes de la variable &compra.
        scanf("%d", &compra);
        sumarPuntos(&puntos, compra);
    }
    printf("Puntos acumulados: %d", puntos);
    return 0;
}
