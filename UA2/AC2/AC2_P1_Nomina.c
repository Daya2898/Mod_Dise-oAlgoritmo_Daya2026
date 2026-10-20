//AC2_P1_nOMINA.C - SISTEMA DE CALCULO NOMINA

#include <stdio.h>
#include <string.h>
 
//Constantes para tasas, limites (CON MAYUSCULA)

#define TASA_CAJA 0.095  // DEDUCCION CAJA = 9.5%
#define TASA_IESS 0.025  //POR IESS =2.5%
#define TASA_RENTA 0.10  //IMPUESTO RENTA 10%
#define LIMITE_RENTA 800.0  //SALARIO LIMITE QUE APLICA RENTA

int main(void){
    //VARIABLES NOMBRE DESCRIPTIVO utilizando  camelCase
    char nombreCompleto[60];

    double salarioBruto; 
    double montoCaja;
    double montoIess;
    double montoRenta = 0.0;
    double salarioNeto; 
    double totalDescuentos;

    // VALIDACION DEL NOMBRE COMPLETO , RECEPCION 
    do{
        printf("Ingrese nombre completo del empleado: ");
        fgets(nombreCompleto, sizeof(nombreCompleto), stdin);
        nombreCompleto[strcspn(nombreCompleto, "\n")] = '\0'; //utilizo salto linea para limpiar

        if(strlen(nombreCompleto) == 0){
            printf("Error: Nombre no puede estar vacio. Intentelo de nuevo.\n");
        }
    }while(strlen(nombreCompleto) == 0);

    //VALIDACION DEL SALARIO BRUTO, RECEPCION - SER MAYOR QUE 0
    do{
        printf("Ingrese salario bruto (> 0): ");
        scanf("%lf", &salarioBruto); 
        if(salarioBruto <= 0) {
            printf("Error: Salario bruto debe ser mayor que cero.\n");
        }
    }while(salarioBruto <= 0);

    //calculando  descuentos de TASA_CAJA-TASA_IESS
    montoCaja = salarioBruto * TASA_CAJA;
    montoIess = salarioBruto * TASA_IESS;

    //APLICACION IMPUESTO SOBRE RENTA = SALARIO SUPERA A 800
    if (salarioBruto > LIMITE_RENTA) {
        montoRenta = salarioBruto * TASA_RENTA;
    }else{
        montoRenta = 0.0;
    } 

    // CALCULANDO SALARIO-NETO
    totalDescuentos = montoCaja + montoIess + montoRenta;
    salarioNeto = salarioBruto - totalDescuentos;

    //RESULTADO FINAL - SALIDA COMPROBANTE
    printf("\n<><><><><><><><><><><><><><><><><><><><>\n");
    printf("          COMPROBANTE DE LA NOMINA         ");
    printf("\n<><><><><><><><><><><><><><><><><><><><>\n");
    printf("Empleado : %s\n", nombreCompleto);
    printf("============================================\n");
    printf("%-20s : $ %10.2f\n", "Salario Bruto", salarioBruto);
    printf("%-20s : $ %10.2f\n", "Descuento CAJA", montoCaja);
    printf("%-20s : $ %10.2f\n", "Descuento IESS", montoIess);
    printf("%-20s : $ %10.2f\n", "Impuesto Renta", montoRenta);
    printf("============================================\n");
    printf("%-20s : $ %10.2f\n", "Salario Neto", salarioNeto);
    printf("============================================\n");
    
     return 0;
}



