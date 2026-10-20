//PR_P2_Desempeno.c
//Empresa evalua a sus colaboradores en tres criterios: puntualidad,calidad, trabajo en equipo . recibe el nombre del colaborador y puntaje de cada criterio(0 a 10); con fuera de rango se vuelve a perdir nombre de criterio, se calcula promedio y nivel (EXCELENTE SI ES 9 A MAS, BUENO si es 7 o mas, 9 menos-necesita mejorar con menos7).
//se logra; mostrar nombre colaborador , su promedio con decimales2, nivel desempeno y criterio con puntaje mas bajo. 
//como se logra;lee nombre con fgets
//for se recorre 3 criterios; cada uno un do-while
//repite la lectura mientras el puntaje este fuera 0 a 10
//acumulan puntajes para calcular promedio
//if / else if decide el nivel segun promedio
//busca menor guardando pósicion, con esa posicion se obtiene nombre del criterio en arreglo de cadenas.
//Resultado final; Promedio: 9.17 | Nivel: EXCELENTE | Puntaje mas bajo: calidad (8.5)
#include <stdio.h>
#include <string.h>
 
// Constantes 
#define CRITERIOS 3                  //cantidad de criterios evaluados 
const double PUNTAJE_MIN = 0.0;      //puntaje minimo permitido 
const double PUNTAJE_MAX = 10.0;     //puntaje maximo permitido 
const double LIMITE_EXCELENTE = 9.0; //promedio minimo para EXCELENTE 
const double LIMITE_BUENO = 7.0;     //promedio minimo para BUENO 
 
int main(void)
{
    //nombres de los criterios, misma posicion 
    const char *criterios[CRITERIOS] = {"puntualidad", "calidad", "trabajo en equipo"};
    double puntajes[CRITERIOS];  //puntaje de cada criterio 
    char nombre[50];             //nombre del colaborador 
    double suma = 0.0;           //acumulador de puntajes 
    double promedio;             //promedio de los tres puntajes 
    int posMenor = 0;            //posicion del puntaje mas bajo 
    int i;                       //indice del for */
 
    printf("=== Evaluacion de desempeno ===\n");
 
    //Lectura del nombre 
    printf("Nombre del colaborador: ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';   //quita el salto de linea 
 
    //lectura y validacion de los puntajes 
    for (i = 0; i < CRITERIOS; i++){
        do
        {
            printf("Puntaje de %s (0 a 10): ", criterios[i]);
            scanf("%lf", &puntajes[i]);
            if (puntajes[i] < PUNTAJE_MIN || puntajes[i] > PUNTAJE_MAX){
                printf(" Puntaje invalido, debe estar entre 0 y 10\n");
            }
        } while (puntajes[i] < PUNTAJE_MIN || puntajes[i] > PUNTAJE_MAX);
 
        suma += puntajes[i];                //acumula
 
        if (puntajes[i] < puntajes[posMenor]){
            posMenor = i;                   //guarda la posicion del menor
        }
    }
 
    //Promedio 
    promedio = suma / CRITERIOS;
 
    //Resultados 
    printf("Colaborador: %s\n", nombre);
    printf("Promedio: %.2f\n", promedio);
 
    if (promedio >= LIMITE_EXCELENTE){
        printf("Nivel: EXCELENTE\n");
    }
    else if (promedio >= LIMITE_BUENO){
        printf("Nivel: BUENO\n");
    }
    else{
        printf("Nivel: NECESITA MEJORAR\n");
    }
 
    printf("Puntaje mas bajo: %s (%g)\n", criterios[posMenor], puntajes[posMenor]);
 
    return 0;
}
 
