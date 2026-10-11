//nota.c - validacion de notas 

#include <stdio.h>
 int main(void){
    // Definición de la variable para la nota
    double nota;

    
    printf("Nota (0 a 100):");
    scanf("%lf", &nota);

    // 1. Validar si la nota está fuera del rango permitido
    if (nota < 0 || nota > 100) {
        printf("Nota invalida: debe estar entre 0 y 100");
      }

    // 2. Si es válida, evaluamos si está aprobada o reprobada
    else {

      if (nota >= 70) {
        printf("Aprobado: %.1lf\n", nota);
      } 
      else {
        printf("Reprobado: %.1lf\n", nota);
      }
    }

    return 0;
 }