// asistencia.c - Matriz de asistencia semanal
// Mostrar la asistencia de 4 estudiantes (P y A), su porcentaje y el total de presentes por día.
//Resultado esperado: Ana 100%, Luis 60%, Sofia 80%, Daniel 80%; presentes por día: 3 3 4 3 3.


#include <stdio.h>

int main(void) {
    // Arreglo de cadenas
    char nombres[4][20] = {"Ana", "Luis", "Sofia", "Daniel"};
    
    //Asistencia (4 estudiantes x 5 días: L, K, M, J, V)
    int asistencia[4][5] = {
        {1, 1, 1, 1, 1}, // Ana
        {1, 0, 1, 1, 0}, // Luis
        {1, 1, 1, 0, 1}, // Sofia
        {0, 1, 1, 1, 1}  // Daniel
    };

    // Recorrido por filas: asistencia y su porcentaje de cada estudiante 
    for (int i = 0; i < 4; i++) {
        // Imprime nombre  con un ancho fijo 
        printf("%-8s", nombres[i]);
        
        int totalPresentesEstudiante = 0;

        //  5 días (columnas) de la fila actual
        for (int j = 0; j < 5; j++) {
            // Usando operador ternario-Si es 1 = 'P', si es 0 = 'A' 
            char letra = (asistencia[i][j] == 1) ? 'P' : 'A';
            printf(" %c", letra);
            
            // Acumula  presencia de  estudiante
            totalPresentesEstudiante += asistencia[i][j];
        }

        // Calculo  porcentaje con casting-total / 5 días * 100
        float porcentaje = ((float)totalPresentesEstudiante / 5) * 100;

        //  porcentaje formateado
        printf("  %.0f%%\n", porcentaje);
    }

    // Recorrido por columnas:  asistencia cada día
    printf("Dia     ");
    for (int j = 0; j < 5; j++) {
        int presentesDia = 0;

        // Suma de filas para cada columna (día)
        for (int i = 0; i < 4; i++) {
            presentesDia += asistencia[i][j];
        }

        printf("%d ", presentesDia);
    }
    printf("\n");

    return 0;
}