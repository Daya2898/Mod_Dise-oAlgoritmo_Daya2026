/*El grupo va a elegir a su representante entre tres candidatos: 1 Ana, 2 Luis y 3 Sofía. Cada estudiante pasa a la computadora y digita el número de su candidato. No se sabe cuántas personas votarán: la votación termina cuando alguien digita 0.
Cualquier otro numero es voto nulo. Al final se muestra una barra de *- con los votos del a*/

#include <stdio.h> //printf y scanf
#include <stdlib.h>//funciones del sistema
#define FIN 0 //se define e inicializa constante

int main(void){//funcion principal

    int voto; //  numero que digita cada estudiante -> 1,, 2, 3, otro o 0
    int total = 0; //contador de votos recibidos(validos como nulos)
    int ana = 0; //CONTADOR VOTOS ANA(CANDIDATO1)
    int luis = 0;
    int sofia = 0;
    int nulos = 0; //CONTADOR VOTO NO VALIDOS
    int c; //candidato dibuja el for externo 1 a 3
    int i; //contador del for interno: una vuelta por *
    int cantidad;//votos del candidato
    int mayor; //por candidato
    int empatados; // candidato con misma cantidad votos


    printf("===== Eleccion de representante ====\n");
    printf("1 Ana  2 Luis 3 Sofia (0 cierra)\n\n");

    //LECTURAS  PREVIAS
    printf("voto: ");
    scanf ("%d", &voto);

    //WHILE CON CENTINELA. Se repite mientras el voto no sea 0
    while (voto != FIN){
        total ++;         //cuenta el voto ->1,2,3,......

        //SWITCH: SUMAR 1 AL CONTADOR DEL CANDIDATO ELEGIDO-SUMATORIA ELEGIDO
        switch(voto){
            case 1: ana++; break;//sale del switch
            case 2: luis++; break;
            case 3: sofia++; break;
            default:  //cualquier otro numero ->5
            nulos++;
            printf(" Voto nulos\n");

        }

        //NUEVA LECTURA : Si la nueva lectura el voto no cambia y el while no termina
        printf("voto: ");
        scanf ("%d", &voto);
    }
    printf("\nVotos recibidos: %d\n", total);

    
    //FOR EXTERNO: Una vuelta por cantidato -> c=1,2,3.....
        for (c = 1; c <= 3; c++){
            switch (c){
            case 1: printf("Ana "); cantidad = ana;break;
            case 2: printf("Luis "); cantidad = luis;break;
            default: case 3: printf("Sofia "); cantidad = sofia;break;
            }

            //FOR INTERNO: ANIDADO UN FOR * Y OTRO POR VOTO ->Ana
        for (i = 1; i <= cantidad; i++)
            printf("*");
        printf("(%d)\n", cantidad);
        

        }

        printf("Nulos: %d\n", nulos);

        //MAYOR  DE TRES   :  el primer lugar 
        mayor = ana;
        if(luis > mayor) mayor = luis;
        if(sofia > mayor) mayor = sofia;
        //empatados
        empatados = 0; 
        if(ana == mayor) empatados++;
        if(luis == mayor) empatados++;
        if(sofia == mayor) empatados++;

        //Decision: SOLO SE EJECUTA EN PRIMER BLOQUE QUE SE CUMPLA
        if (mayor == 0)
        printf("No hubo votos válidos\n");
        else if (empatados < 1)
        printf("empate con %d votos: se repite la votacion\n", mayor);

        else if (ana == mayor)
        printf("Gana Ana con %d votos\n", mayor);//3vtos

        else if (luis == mayor)
        printf("Gana Luis con %d votos\n", mayor);

        else if (sofia == mayor)
        printf("Gana Sofia con %d votos\n", mayor);

   
        system("pause");
  
    return 0; //fin normal del programa
}
