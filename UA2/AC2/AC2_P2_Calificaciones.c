//AC2_P2_CALIFICACIONES.C - VALIDACION DE CALIFICACIONES ESTUDIANTILES

#include<stdio.h>
#include<string.h>

//CONSTANTES -LIMITES DE NOTAS Y CONDICIONES
#define NUMR_NOTAS 3
#define NOT_MIN 0.0
#define NOT_MAX 100.0
#define PROMEDIO_APROBADO 70.0
#define PROMEDIO_RIESGO 60.0

int main(void){
    //DEFINICION DE VARIABLES NOMBRE DESCRIPTIVO utilizando  camelCase
    int i; 
    char condicion[20];
    char nombreEstudiante[60];

    float notaAlta;
    float promedio;
    float sumNotas = 0.0;
    float notas[NUMR_NOTAS];

    printf("<><><> Calificaciones del estudiante <><><>\n");

    //Ingreso del nombre completo del estudiantes
    printf("Nombre del estudiante: ");
    fgets(nombreEstudiante, sizeof(nombreEstudiante), stdin);
    nombreEstudiante[strcspn(nombreEstudiante, "\n")] = '\0';//utilizo salto linea para limpiar
    
    //VALIDACION, TRES CALIFICACIONES CON ARREGLO Y DO---WHILE
    for (i = 0; i < NUMR_NOTAS; i++){
        do {
            printf("Calificacion %d (0 a 100):", i + 1);
            scanf("%f", &notas[i]);
            if (notas[i] < NOT_MIN || notas[i] > NOT_MAX){
                printf("Incorrecto: Calificacion fuera de rango. Intentelo de nuevo.\n");
            }
        }while (notas[i] < NOT_MIN || notas[i] > NOT_MAX);
    }

    //CALCULO DE SUMA, PROMEDIO, BUSQUEDA DE CALIFICACION MAS ALTA 
    notaAlta = notas[0];// inicializa donde la primera es mayor
    for (i = 0; i < NUMR_NOTAS; i++){
        sumNotas += notas[i];
        if (notas[i] > notaAlta){
            notaAlta = notas[i];
        }
    }
    promedio = sumNotas / NUMR_NOTAS;

    //CONDICION ACADEMICA CON STRCPY PARA GUARDAR
    if (promedio >= PROMEDIO_APROBADO){
        strcpy(condicion, "APROBADO");
    }else if (promedio >= PROMEDIO_RIESGO){
        strcpy(condicion, "EN RIESGO");
    }else{
        strcpy(condicion, "NO APROBADO");
    }

    //RESULTADO FINAL REPORTE
    printf("\n><><>< Resultado ><><><\n");
    printf("Estudiante: %s\n", nombreEstudiante);
    printf("Calificacion 1: %.1f\n", notas[0]);
    printf("Calificacion 2: %.1f\n", notas[1]);
    printf("Calificacion 3: %.1f\n", notas[2]);
    printf("Promedio: %.2f\n", promedio);
    printf("Nota mas alta: %.1f\n", notaAlta);
    printf("Condicion: %s\n", condicion);
    printf("><><><><><><><><><><><><><><><>");
    
    return 0;

}