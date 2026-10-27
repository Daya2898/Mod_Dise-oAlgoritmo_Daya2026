/*dado.c-Simular 600 lanzamientos de un dado y mostrar las frecuencias.
Qué se logra: Usar números aleatorios y arreglos como contadores con funciones.
Cómo se logra: Con rand y srand de stdlib.h, un arreglo frecuencia-7-y un ciclo for.
 */

#include <stdio.h>
#include <stdlib.h>

//Prototipo de la función 
int lanzarDado(void);

int main(void) {
    // Arreglo para contar las veces que sale(usamos de 1 a 6)
    int frecuencia[7] = {0}; 
    int i, j;

    //Fija para los números aleatorios
    srand(2026);

    // Simular 600 lanzamientos
    for (i = 1; i <= 600; i++) {
        int cara = lanzarDado(); // Llama  la función y guarda el tiro (1 a 6)
        frecuencia[cara]++;       // Aumenta contador de la cara que salió
    }

    //Resultados y barra de asteriscos * por cada 10 lanzamientos
    for (i = 1; i <= 6; i++) {
        printf("Cara %d: %d ", i, frecuencia[i]);
        
        // Se dibuja asterisco por cada repeticion
        for (j = 0; j < frecuencia[i] / 10; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

//Definición de la función lanzarDado
int lanzarDado(void) {
    return rand() % 6 + 1; // Devuelve un número entero aleatorio entre 1 y 6
}