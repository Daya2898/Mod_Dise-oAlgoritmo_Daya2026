//tablas.c - resuelve la tabla del 7
#include <stdio.h>

#define CENTINELA 0 // EL 0 INDICA QUE NO HAY TABLAS

int main (void){
    //declaracion de variables
    int numero, i;
    int tablas = 0;

    //LECTURA PREVIA: EL NUMERO SE LEE ANTES DEL WHILE ->7
    printf("Numero de la tabla (0 para terminar): ");
    scanf("%d", &numero);

    //WILE con centinela : repite mientras en numero no sea 0 
    while( numero != CENTINELA){
        
        //FOR anidado: 100 vueltas por cada numero -> 1=1, 2...., 10
        for (i = 1; i <= 10; i++){
            //%2d alinea en 2 espacios -> 7 x 1 =7 .... 7x10 = 70
            printf("%d x %2d = %2d\n", numero, i, numero * i );
        }

        tablas++; //CUENTA LA TABLA MOSTRADA  -> 1 LUEGO 2 SUCESIVAMENTE

        //SIGUIENTE DATO AL FINAL DEL CUERPO -> 3, LUEGO 0
        printf("Numero de la tabla (0 para terminar): ");
        scanf("%d", &numero);


    }

    //DESPUES DEL WHILE (SE DIGITO 0) ->TABLAS MOSTRADAS 2 
    printf("Tablas mostradas: %d\n", tablas);


    return 0;
}