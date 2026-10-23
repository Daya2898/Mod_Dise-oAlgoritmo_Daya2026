//horas.c - Horas de estudio a la semana
/*Enunciado: Registrar las horas de estudio de 3 estudiantes de lunes a jueves
se digite el nombre y las horas de estudio de cada dia.
Mostrar una tabla con el total de cada estudiante, quien estudio más, el dia con mas horas y buscar a una persona del grupo por su nombre */

#include <stdio.h>
#include <string.h>

//Definir constantes
#define EST 3 //FILAS de matriz
#define DIAS 4 //COLUMNAS

int main (void){
    //ARREGLO DE CADENAS para los 3 nombres
    char nombres[EST][15]; // DE LOS 15 CARACTERES 14 SON PARA EL NOMBRE YU 1 para '/0'

    //Matriz de horas: 3 filas para estudiantes y 4 columnas para los dias
    int horas[EST][DIAS];

    //AREGLO DE CADENAS: NOMBRES CORTOS DE LOS DIAS
    char dias[DIAS][4] = {"Lun", "Mar", "Mie", "Jue"};
    //Se crean los indices de fila y columnas
    int e;
    int d;

    //ARREGLO: total  por estudiantes. total[e] es la suma de la fila e. Guardar y buscar al mayor 
    int total[EST];

    //POSICION: de quien estudio mas
    int mejor;

    //ACUMULADO: de columna(horas del grupo en un dia)
    int sumaDia;

    //suma mayor dia
    int sumaMayor;

    //POSICION: DIA CON MAS HORAS
    int diaMejor;

    //CADENA: con el nombre a buscar
    char buscado[15];

    //POSICION: donde aparece nombre buscado
    int encontrado;

    //================LECTURA CON LOS FOR ANIDADOS =================
    //ciclo externo: una vuelta por estudiante(fila)

    for(e = 0; e < EST; e++){
        //pedimos nombre del estudiante 
        printf("Nombre del estudiante %d: ", e + 1);
        //leer una palabra en la fila de nombres 
        scanf("%14s", nombres[e]);

        //Ciclo interno: una vuelta por dia (columna) de la fila 
        for(d = 0; d < DIAS; d++){
            //pedir las horas del dia
            printf(" Horas del %s: ", dias[d]);
            //leer un entero en la celda
            scanf("%d", &horas[e][d]);
        }

    }

    //================TABLA===================
    //Con encabezado con la palabra "Nombre".
    printf("\n%-8s", "Nombre");

    //FOR para recorrer dias para el encabezado
    for (d = 0; d < DIAS; d++);
    //mostrar cada dia 
    printf("%5s", dias[d]);

    //titulo de la ultima columna y salto de linea
    printf("%7s\n", "Total");

    //una fila de la tabla por estudiante
    for (e = 0; e < EST; e++) {
        //reinicia el total de la fila e
        total[e] = 0;
        //Mostrar nombre
        printf("%-8s", nombres[e]);

        //recorre la columna de la fila e 
        for (d = 0; d < DIAS; d++) {
            //mostrar las horas de la celda
            printf("%5d", horas[e][d]);
            //suma la celda al total
            total[e] += horas[e][d];
        }
        //mostrar el total 
            printf("%7d\n", total[e]);
    }


    //================Mayor del arreglo total================
    //supone que el primero estudio mas
    mejor = 0;
    //recorre los demas estudiantes (posiciones 1 y 2).
    for (e = 1; e < EST; e++)
    //comparar totales
    if (total[e] > total[mejor])
    mejor = e;

    //mostrar quien estudio mas
    printf("\nEstudio mas: %s (%d horas)\n", nombres[mejor], total[mejor]);

    //===============Dia con mas horas (Suma por columna)=======================
    //mayor suma inicial en 0
    sumaMayor = 0;
    diaMejor = 0;

    //recorrer columnas
    for (d = 0; d < DIAS; d++){
        //REINICIAMOS EL ACUMULADO
        sumaDia = 0;

        //recorrer filas de esa columna
        for (e = 0; e < EST; e++)
        //suma de celda
        sumaDia += horas[e][d];

        //Comparar la suma del dia mayor

        if (sumaDia > sumaMayor){
            //guardar la nueva mayor
            sumaMayor = sumaDia;
            //Guarda al posicion
            diaMejor = d;
        }

    }
    //Mostrar el dia con mas horas
    printf("Dia con mas horas: %s (%d horas)\n", dias[diaMejor], sumaMayor);

    //===============Busqueda por nombre===========================
    //pedir nombre a buscar
    printf("\nBuscar estudiante: ");
    //lee la palabra
    scanf("%14s", buscado);
    //marca que todavia no aparece
    encontrado = -1;//si el for no encuentra el nombre sigue en -1
    //recorrer los nombres }
    for (e = 0; e < EST; e++)
    //compara las dos cadenas
    if (strcmp(buscado, nombres[e]) == 0) //strcmp devuelve 0 sin son iguales letra por letra
    encontrado = e;

    //revisa si encontro 
    if (encontrado >= 0)
    //Muestra el total encontrado
    
    printf("%s estudio %d horas\n", nombres[encontrado], total[encontrado]);
    //en caso que no aparece

    else
    
    printf("%s no esta en la lista\n", buscado);
    //finalizamos
    return  0;  
}