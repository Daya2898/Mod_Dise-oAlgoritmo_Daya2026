//temepratura.c -- Temperaturas de la semana
/*Enunciado: registrar la temperatura maxima de cada dia- L a D
validar en un rango de 0 a 45 
calcular el promedio
identificar el dia mas caluroso y contar cuantos dias superan ese promedio*/

#include <stdio.h>




int main(void){
    //arreglo de cadenas nombre de los dias
    char dias[7][4] = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"};

    //Arreglo almacenar las 7 temperaturas max
    float temp[7];

    float suma = 0.0;
    float promedio = 0.0;
    int posMax = 0;
    int contaSobre = 0;
    int i;

    printf("<><><><><><> Temperaturas de la semana <><><><><><>\n");

    //Pedir y validar temp cada dia (0 a 45)
    for(i = 0; i < 7; i++){
    do {
            printf("Temperatura del %s (0 a 45): ", dias[i]);
            scanf("%f", &temp[i]);

            // Validación si el número está fuera del rango permitido
            if (temp[i] < 0 || temp[i] > 45) {
                printf("Error: Ingrese un valor entre 0 y 45.\n");
            }
        } while (temp[i] < 0 || temp[i] > 45);

        // Sumar la temperatura ingresada para luego calcular el promedio
        suma += temp[i];
    }

    //Calcula el promedio de la semana usando casting a float
    promedio = suma / 7.0;

    //Encontrar  día más caluroso buscando la posición (indice) del mayor valor
    posMax = 0;
    for (i = 1; i < 7; i++) {
        if (temp[i] > temp[posMax]) {
            posMax = i; // Actualiza posición si encuentra una temperatura mayor
        }
    }

    // Resultado de reporte de la semana
    printf("\n<><><><><><> Reporte de la semana <><><><><><>\n");
    for (i = 0; i < 7; i++) {
        printf("%s: %.1f C\n", dias[i], temp[i]);
    }

    printf("Promedio: %.2f C\n", promedio);
    printf("Mas caluroso: %s (%.1f C)\n", dias[posMax], temp[posMax]);

    // Muestra  días que superaron el promedio y su cantidad total
    printf("Sobre el promedio: ");
    for (i = 0; i < 7; i++) {
        if (temp[i] > promedio) {
            printf("%s ", dias[i]);
            contaSobre++;
        }
    }
    printf("(%d dias)\n", contaSobre);

    return 0;

}