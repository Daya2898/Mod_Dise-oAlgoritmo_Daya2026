//ventas.c ventas de cadena de sodas por sucursal y por dia
//Que logra: guardar en una matriz  las ventas de 3 sucursales en 4 dias.
/*sumar cada sucursal por medio de la (fila) y cada dia por medio de la (columna) e identificar la sucursal que más vendio , con su nombre guardado en una cadena, 
Resultado esperado: Centro 470, Norte 350, Sur 410; por dia 330 270 330; Sucursal con más ventas: centro(470). */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>  //strcpy 

//ConStantes
#define SUC 3   //filas sucursales
#define DIAS 4  //columnas dias

int main(void){
    //Arreglo de cadenas: una fila por nombre (hasta 9 letras + '\0')
    char nombres[SUC] [10] = {"Centro", "Norte", "Sur"};

    //Ventas en miles de colones 
    int ventas[SUC] [DIAS] = { {120, 100, 130, 120},
                              {90, 80, 100, 80},
                              {120, 90, 100, 100} };
    char mejor[10]; //nombre de la sucursal ganadora
    int s, d, total, totalDia, mayor = 0;

    //Encabezado : D1 A D4
    printf("%-8s", "");
    for(d = 0; d < DIAS; d++){
        printf("  D%d", d + 1);
    }
    printf("  |  Total\n");

    //RECORRIDO POR FILAS   
    for (s = 0; s < SUC; s++){
        total = 0;          //reinicia cada fila en 0
        printf("%-8S",nombres[s]);//nombre ala izquierda
        for (d = 0; d < DIAS; d++){
            printf("%5d", ventas[s] [d]);
            total += ventas [s] [d];
        }
        printf("  | %5d\n", total); //470,3750,140

        //GUARDAR LA VARIABLE CON MAYOR TOTAL; strcpy copia el nombre
        if (total > mayor){
            mayor = total;
            strcpy(mejor, nombres[s]); //mejor = centro
        }
        
    }
    //RECORRIDO POR COLUMNAS . EL FOR 
    printf("%-8s", "Dia");
    for (d = 0; d < DIAS; d++){
        totalDia = 0;
        for (s = 0; s < SUC; s++){
            totalDia += ventas [s] [d];
        }
        printf("%5d", totalDia); //330 270 330 300 
    }
    printf("\n");
    //Salidas SUCURSAL CON MAS VENTAS
    printf("Sucursal con mas ventas: %s (%d)\n", mejor, mayor);
    system("pause");

    return 0;

}