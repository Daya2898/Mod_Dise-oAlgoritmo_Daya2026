/*notas_grupo.c
Enunciado: Organizar las notas de un grupo pequeño de estudiantes.
Registrar notas en matriz, calcular promedios por estudiante y por evaluacion, y buscar estudiantes.
Usando matrices, arreglos paralelos, ciclos for anidados y funciones como strcmp.
Tabla de notas con promedios, promedios por evaluacion, mejor estudiante y busqueda por nombre.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    // Matriz 4 filas-estudiantes-por 3 columnas (evaluaciones)
    int notas[4][3];
    
    // Arreglo de cadenas para guardar los nombres de los 4 estudiantes
    char estudiantes[4][15];
    
    // Arreglo para almacenar el promedio de cada estudiante
    float prom[4];
    
    // Arreglo para almacenar los promedios de cada evaluacion
    float promEvalue[3] = {0.0, 0.0, 0.0};
    
    char nombreBuscado[15];
    char condicion[15];
    int posMejor = 0;
    int i, j;
    int encontrado = 0;

    printf("<><><> Notas del grupo <><><>\n");

    //Pedir los nombres y las 3 notas de cada estudiante (validacion de 0 a 100)
    for (i = 0; i < 4; i++) {
        printf("Nombre del estudiante %d: ", i + 1);
        scanf("%s", estudiantes[i]); // Lee el nombre-una palabra

        for (j = 0; j < 3; j++) {
            do {
                printf(" Nota %d de %s: ", j + 1, estudiantes[i]);
                scanf("%d", &notas[i][j]);

                if (notas[i][j] < 0 || notas[i][j] > 100) {
                    printf("Error: La nota debe estar entre 0 y 100.\n");
                }
            } while (notas[i][j] < 0 || notas[i][j] > 100);
        }
    }

    // Mostrar la tabla con nombre, notas y el promedio-recorrido por filas
    printf("\nNombre    N1     N2     N3     Promedio\n");
    for (i = 0; i < 4; i++) {
        float sumaFila = 0.0;
        for (j = 0; j < 3; j++) {
            sumaFila += notas[i][j]; // Suma las notas de la fila actual
        }
        prom[i] = sumaFila / 3.0; // Calcula el promedio usando float

        // Imprime los datos estructurados en columnas
        printf("%-9s %-6d %-6d %-6d %-8.2f\n", estudiantes[i], notas[i][0], notas[i][1], notas[i][2], prom[i]);
    }

    //Calcular y mostrar promedio de cada evaluacion-recorrido por columnas
    for (j = 0; j < 3; j++) {
        float sumaColumna = 0.0;
        for (i = 0; i < 4; i++) {
            sumaColumna += notas[i][j]; // Suma los valores de la columna actual
        }
        promEvalue[j] = sumaColumna / 4.0;
        printf("Promedio de la evaluacion %d: %.2f\n", j + 1, promEvalue[j]);
    }

    //Encontrar el estudiante con el mejor promedio
    for (i = 1; i < 4; i++) {
        if (prom[i] > prom[posMejor]) {
            posMejor = i; // Actualiza la posicion si encuentra un promedio mayor
        }
    }
    printf("Mejor promedio: %s (%.2f)\n", estudiantes[posMejor], prom[posMejor]);

    //Busca un estudiante por su nombre usando strcmp
    printf("Buscar estudiante: ");
    scanf("%s", nombreBuscado);

    for (i = 0; i < 4; i++) {
        if (strcmp(estudiantes[i], nombreBuscado) == 0) {
            encontrado = 1;
            
            // Asigna la condicion segun el promedio con strcpy
            if (prom[i] >= 70.0) {
                strcpy(condicion, "APROBADO");
            } else {
                strcpy(condicion, "NO APROBADO");
            }
            printf("%s: %.2f %s\n", estudiantes[i], prom[i], condicion);
        }
    }

    if (!encontrado) {
        printf("Estudiante no encontrado.\n");
    }

    return 0;
}