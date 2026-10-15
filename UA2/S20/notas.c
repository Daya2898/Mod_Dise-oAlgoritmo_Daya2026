//notas.c la trabajamos con arreglo. ahora las guardan
#include <stdio.h>
#include <stdlib.h>
#define  N 5 

int main(void){
    double notas[N]; //definicion del arreglo
    double suma = 0 , promedio, mayor, menor;
    int i;

    //lectura de datos
    for ( i = 0; i < N; i++) {
        //VALIDACION
        do {
            printf("Nota %d (0 a 100):", i + 1);
            scanf("%lf", &notas[i]);//guarda en notas [i]
        }while (notas[i] < 0 || notas[i] > 100);
        suma += notas [i];
        
        }
        promedio = suma / N;

        //Mayor y menor . se comienza desde la primera nota y se compara con el resto
        mayor = notas[0];
        menor = notas[0];
      for (i = 1; i < N; i++){
       if (notas[i] > mayor){
            mayor = notas[i];
       }

    
       if (notas[i] < menor){
            menor = notas[i];
       }
    }
    printf("Promedio: %.2f\n", promedio);
    printf("Mayor: %.lf Menor: %.lf\n", mayor, menor);

    //segundo recorrido
    printf("Sobre el promedio: ");
    for (i = 0; i < N; i++){
        if (notas[i] > promedio){
            printf(" %.lf", notas[i]);
        }
    }
    printf("\n");

    system ("pause");

    return 0;

}
    
